/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:08:31 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:14:43 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
*	Auxiliar function to draw a circle
*/

static void	dot_util(t_data *data, t_point pixel, t_point point, int coord)
{
	int	i;

	i = point.cords[X];
	while (i <= point.cords[X] + coord)
	{
		pixel.cords[X] = i;
		pixel.cords[Y] = (int)point.cords[Y] + coord;
		my_putpixel(data, pixel);
		pixel.cords[X] = i;
		pixel.cords[Y] = (int)point.cords[Y] - coord;
		my_putpixel(data, pixel);
		i++;
	}
}

/*
*	This function draw a circule in t_point position and with r radius
*/

void	draw_dot(t_data *data, t_point point, int radius)
{
	int		cords[2];
	int		change[2];
	int		radius_error;
	t_point	pixel;

	cords[X] = radius;
	cords[Y] = 0;
	change[X] = 1 - (radius << 1);
	change[Y] = 0;
	radius_error = 0;
	pixel.color = point.color;
	while (cords[X] >= cords[Y])
	{
		dot_util(data, pixel, point, cords[Y]);
		dot_util(data, pixel, point, cords[X]);
		cords[Y]++;
		radius_error += change[Y];
		change[Y] += 2;
		if (((radius_error << 1) + change[X]) > 0)
		{
			cords[X]--;
			radius_error += change[X];
			change[X] += 2;
		}
	}
}

// This function generates the color of each pixel between groundcolor 
// and topcolor To do that get the RGB chanels independtly and create a 
// linear escale between each channel. The function return the color 
// number "pix" of line "0->len".
int	gradient(int groundcolor, int topcolor, int len, int point)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((topcolor >> 16) - \
					(groundcolor >> 16)) / (double)len;
	increment[1] = (double)(((topcolor >> 8) & 0xFF) - \
					((groundcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((topcolor & 0xFF) - (groundcolor & 0xFF)) \
					/ (double)len;
	new[0] = (groundcolor >> 16) + round(point * increment[0]);
	new[1] = ((groundcolor >> 8) & 0xFF) + round(point * increment[1]);
	new[2] = (groundcolor & 0xFF) + round(point * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

// apply a shadow effect to the points that are behind the camera
void	apply_shadow(t_point *points, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (points[i].cords[Z] < 0)
			points[i].paint = 0;
		else
			points[i].paint = 1;
		i++;
	}
}

/*
*	This function checks if the whole line is out of the window to avoid the 
*	operations and getting better the performance.
*	Then calculate all the point of the line with the Bresenham's line algorithm
*/

int	draw_line(t_data *data, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

	if (valid_pixel(start) == 0 && valid_pixel(end) == 0)
		return (0);
	delta.cords[X] = end.cords[X] - start.cords[X];
	delta.cords[Y] = end.cords[Y] - start.cords[Y];
	pixels = sqrt((delta.cords[X] * delta.cords[X]) + \
			(delta.cords[Y] * delta.cords[Y]));
	len = pixels;
	delta.cords[X] /= pixels;
	delta.cords[Y] /= pixels;
	pixel.cords[X] = start.cords[X];
	pixel.cords[Y] = start.cords[Y];
	while (pixels > 0)
	{
		pixel.color = gradient(start.color, end.color, len, len - pixels);
		my_putpixel(data, pixel);
		pixel.cords[X] += delta.cords[X];
		pixel.cords[Y] += delta.cords[Y];
		pixels = pixels - 1;
	}
	return (1);
}
