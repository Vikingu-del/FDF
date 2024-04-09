/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:08:48 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:14:45 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
*	Iterates all the points and add the "move" traslation
*/

void	traslate(t_point *points, t_point move, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].cords[X] = points[i].cords[X] + move.cords[X];
		points[i].cords[Y] = points[i].cords[Y] + move.cords[Y];
		points[i].cords[Z] = points[i].cords[Z] + move.cords[Z];
		i++;
	}
}

/*
*	Iterates all the points and multiply by scale
*/

void	scale_map(t_point *points, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].cords[X] = points[i].cords[X] * scale;
		points[i].cords[Y] = points[i].cords[Y] * scale;
		points[i].cords[Z] = points[i].cords[Z] * scale;
		i++;
	}
}

/*
*	Set the values to draw ISOMETRIC view
*/

void	isometric(t_map *map)
{
	map->sphere = 0;
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 30;
	map->curve_range = 0;
	map->src.cords[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->src.cords[Y] = WINY / 2;
}

/*
*	Set the values to draw PARALLEL view
*/

void	parallel(t_map *map)
{
	map->sphere = 0;
	map->ang[X] = 90;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->curve_range = 0;
	map->src.cords[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->src.cords[Y] = WINY / 2;
}

/*
*	Iterate all the point to move the z value depending the range 
*	and the x and y position
*/

void	curving(t_point *points, int len, float curve_range)
{
	int		i;
	float	x_squared;
	float	y_squared;

	x_squared = 0;
	y_squared = 0;
	i = 0;
	while (i < len)
	{
		x_squared = pow(points[i].cords[X], 2);
		y_squared = pow(points[i].cords[Y], 2);
		points[i].cords[Z] -= curve_range * (x_squared + y_squared);
		i++;
	}
}
