/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:10:18 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 20:12:02 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
*	Call all the functions to modify the points in the space
*/

static void	parse_map(t_data *data, t_point *projections)
{
	z_scaling(projections, data->map.z_scale, data->map.len);
	curving(projections, data->map.len, data->map.curve_range);
	if (data->map.sphere)
		sphering(&data->map, projections);
	rotate_x(projections, projections, data->map.ang[X], data->map.len);
	rotate_y(projections, projections, data->map.ang[Y], data->map.len);
	rotate_z(projections, projections, data->map.ang[Z], data->map.len);
	if (data->map.sphere && data->map.shadows)
		apply_shadow (projections, data->map.len);
	orto_projection (projections, projections, data->map.len);
	scale_map (projections, data->map.scale, data->map.len);
	traslate(projections, data->map.source, data->map.len);
}

/* 
*	This function checks if any point is out of the limits of the screen
*/

static int	within_boundaries(t_point *points, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (points[i].coords[X] < (MENU_WIDTH + FIT_MARGIN) || \
			points[i].coords[X] > (WINX - FIT_MARGIN))
			return (0);
		if (points[i].coords[Y] < FIT_MARGIN || \
			points[i].coords[Y] > (WINY - FIT_MARGIN))
			return (0);
		i++;
	}
	return (1);
}

/* 
*	This function iterate n times until get the scale needed
*	to fit the screen.
*/

static void	fiting(t_data *data, t_point *projection)
{
	data->map.source.coords[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH + 35;
	data->map.source.coords[Y] = WINY / 2;
	data->map.source.coords[Z] = 0;
	data->map.scale = 1;
	copy_map_points(data->map.points, projection, data->map.len);
	parse_map(data, projection);
	while ((within_boundaries(projection, data->map.len)))
	{
		copy_map_points(data->map.points, projection, data->map.len);
		parse_map(data, projection);
		data->map.scale = data->map.scale + 0.2;
	}
}

void	draw_map_points(t_data *data, t_point *projection, int fit)
{
	if (data->map.stars)
		generate_stars(data);
	if (fit)
		fiting(data, projection);
	if (data->map.wires)
		wiring(data, projection);
	if (data->map.dots)
		doting(data, projection);
}

/* 
*	This function draw the projection of map->points acording all
*	the modifiers (x,y,z, scale..). If fit = 1, will caculate the 
*	scale needed to fit the screen.
*/

int draw_map(t_data *data, int should_fit_window)
{
    t_point *projected_points;
    clock_t start_time;

    start_time = clock();
    projected_points = malloc(data->map.len * sizeof(t_point));
    if (projected_points == NULL)
        exit_with_error(ERR_MEM);
    data->map.renders++;
    generate_background(data, data->map.colors.backcolor, \
        data->map.colors.menucolor);
    copy_map_points(data->map.points, projected_points, data->map.len);
    parse_map(data, projected_points);
    draw_map_points(data, projected_points, should_fit_window);
    mlx_put_image_to_window(data->vars.mlx, data->vars.win, \
        data->picture.img, 0, 0);
    draw_menu(data);
    free(projected_points);
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    data->map.performance = elapsed_time;
    return (1);
}
