/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:12:49 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 20:17:31 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* 
*	This function copy len points of the array from src to projection
*/

void	copy_map_points(t_point *map_points, t_point *projection, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		projection[i] = map_points[i];
		i++;
	}
}

/*
*	This function checks if the point is in the windows limit to avoid draw it
*/

int	valid_pixel(t_point pixel)
{
	if (pixel.coords[X] < 0 || pixel.coords[X] > WINX)
		return (0);
	if (pixel.coords[Y] < 0 || pixel.coords[Y] > WINY)
		return (0);
	return (1);
}
