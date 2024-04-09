/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:08:48 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 19:39:08 by eseferi          ###   ########.fr       */
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
		points[i].coords[X] = points[i].coords[X] + move.coords[X];
		points[i].coords[Y] = points[i].coords[Y] + move.coords[Y];
		points[i].coords[Z] = points[i].coords[Z] + move.coords[Z];
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
		points[i].coords[X] = points[i].coords[X] * scale;
		points[i].coords[Y] = points[i].coords[Y] * scale;
		points[i].coords[Z] = points[i].coords[Z] * scale;
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
	map->source.coords[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.coords[Y] = WINY / 2;
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
	map->source.coords[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.coords[Y] = WINY / 2;
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
		x_squared = pow(points[i].coords[X], 2);
		y_squared = pow(points[i].coords[Y], 2);
		points[i].coords[Z] -= curve_range * (x_squared + y_squared);
		i++;
	}
}