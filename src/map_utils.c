/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:11:10 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:15:15 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	wire_line(t_point *point, t_data *data, int density, int line);

/* 
*	This function iterate all the points of the wire array and draw a line between:
*	--> wire[i] and wire [i + density]
*	--> wire[i] and wire [i + x_max * density]
*/

void	wiring(t_data *data, t_point *wire)
{
	int	i;
	int	density;

	density = 8 / data->map.scale;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < data->map.len)
	{
		wire_line (&wire[i], data, density, i / data->map.limits.cords[X]);
		i = i + data->map.limits.cords[X] * density;
	}
}

void	wire_line(t_point *point, t_data *data, int density, int line)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	while (i < (int)data->map.limits.cords[X])
	{
		x_end = i + density;
		if (x_end >= (int)data->map.limits.cords[X])
			x_end = (int)data->map.limits.cords[X] - 1;
		y_end = i + (int)data->map.limits.cords[X] * density;
		if (point[i].paint)
		{
			draw_line(data, point[i], point[x_end]);
			if (line + density < (int)data->map.limits.cords[Y])
				draw_line(data, point[i], point[y_end]);
		}
		i += density;
	}
}

/* 
*	Colorize all the points of the map
*/

void	apply_color_scheme(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		load_color((int)map->limits.cords[Z], map->zmin, \
		&map->points[i], map->colors);
		i++;
	}
}

/* 
*	This function iterate all the points of the array and draw a dot for each point
*/

void	doting(t_data *data, t_point *projection)
{
	int	i;

	i = 0;
	while (i < data->map.len)
	{
		if (projection[i].paint)
			draw_dot(data, projection[i], 1);
		i++;
	}
}

// This function iterate through all z coordinates and scales them to fit the 
// screen in a way that the highest point of the map is at the top of the 
// screen and the lowest point is at the bottom.
void	z_scaling(t_point *projected, float z_scale, int map_size)
{
	int	point;

	point = 0;
	while (point < map_size)
	{
		projected[point].cords[Z] = projected[point].cords[Z] / z_scale;
		point++;
	}
}
