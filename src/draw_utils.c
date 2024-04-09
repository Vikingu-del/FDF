/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:49 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 19:38:19 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	used to set the color value of a pixel in the bitmap image, taking 
	into account the byte order of the system.
*/

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

/*
*	This function calculate the position of the pixel in the img array:
*		array_pixe_position = pixel.axis[y] * WINX * 4 + 4 * pixel.axis[y]
*	and fill the 4 colorbytes calling the set_color function
*/

int	my_putpixel(t_data *data, t_point pixel)
{
	int	mypixel;
	int	alpha;

	alpha = 0;
	if (pixel.coords[X] < MENU_WIDTH)
		alpha = -10;
	if (pixel.coords[X] >= WINX || pixel.coords[Y] >= WINY || \
		pixel.coords[X] < 0 || pixel.coords[Y] < 0)
		return (-1);
	mypixel = ((int)pixel.coords[Y] * WINX * 4) + ((int)pixel.coords[X] * 4);
	if (data->picture.bitxpixel != 32)
		pixel.color = mlx_get_color_value(data->vars.mlx, pixel.color);
	set_color(&data->picture.buffer[mypixel], \
		data->picture.endian, pixel.color, alpha);
	return (0);
}

/*
*	This function set the color value to 32bits value in case of need
*/

int	get_color(t_data *data, int color)
{	
	if (data->picture.bitxpixel != 32)
		color = mlx_get_color_value(data->vars.mlx, color);
	return (color);
}

/*
*	This function generate all the pixel colors and fill the img array propertly
*/

void	generate_background(t_data *data, int backcolor, int menucolor)
{
	int	coords[2];
	int	pixel;
	int	color;

	backcolor = get_color(data, backcolor);
	menucolor = get_color(data, menucolor);
	coords[X] = 0;
	coords[Y] = 0;
	while (coords[Y] < WINY)
	{
		while (coords[X] < WINX)
		{
			if (coords[X] < MENU_WIDTH)
				color = menucolor;
			else
				color = backcolor;
			pixel = (coords[Y] * data->picture.lines) + (coords[X] * 4);
			set_color(&data->picture.buffer[pixel], \
						data->picture.endian, color, 1);
			coords[X]++;
		}
		coords[Y]++;
		coords[X] = 0;
	}
}

void	generate_stars(t_data *data)
{
	int		i;
	t_point	star;
	int		lim_x[2];
	int		lim_y[2];

	if (data->map.sphere == 0)
		return ;
	lim_x[0] = data->map.source.coords[X] - (data->map.radius * data->map.scale);
	lim_x[1] = data->map.source.coords[X] + (data->map.radius * data->map.scale);
	lim_y[0] = data->map.source.coords[Y] - (data->map.radius * data->map.scale);
	lim_y[1] = data->map.source.coords[Y] + (data->map.radius * data->map.scale);
	i = 0;
	while (i < 200)
	{
		star.coords[X] = rand() % WINX;
		star.coords[Y] = rand() % WINY;
		star.color = GRAY;
		if ((star.coords[X] < lim_x[0] || star.coords[X] > lim_x[1]) \
		|| ((star.coords[Y]) < lim_y[0] || star.coords[Y] > lim_y[1]))
			draw_dot(data, star, 1);
		i++;
	}
}