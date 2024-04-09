/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:09:05 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:14:48 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sphering(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].cords[X] = (map->radius + points[i].cords[Z]) * \
		cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].cords[Y] = (map->radius + points[i].cords[Z]) * \
		sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].cords[Z] = (map->radius + points[i].cords[Z]) * \
		cos(points[i].polar[LAT]);
		i++;
	}
}

// this function converts the cartesian to polar coordinates
void	cart_to_pol(t_map *map)
{
	int		i;
	float	theta;
	float	fita;

	theta = (M_PI * 2) / (map->limits.cords[X] - 1);
	fita = M_PI / (map->limits.cords[Y]);
	map->radius = map->limits.cords[X] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[LONG] = -(map->points[i].cords[X]) * theta;
		if (map->points[i].cords[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].cords[Y]) + \
			(map->limits.cords[Y] / 2)) * fita - 0.5 * fita;
		else
			map->points[i].polar[LAT] = (map->points[i].cords[Y] + \
			(map->limits.cords[Y] / 2) - 1) * fita + 0.5 * fita;
		i++;
	}
}
