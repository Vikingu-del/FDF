/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:09:05 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 19:38:51 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sphering(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].coords[X] = (map->radius + points[i].coords[Z]) * \
		cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].coords[Y] = (map->radius + points[i].coords[Z]) * \
		sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].coords[Z] = (map->radius + points[i].coords[Z]) * \
		cos(points[i].polar[LAT]);
		i++;
	}
}

// this function converts the cartesian to polar coordinates
void	cart_to_pol(t_map *map)
{
	int		i;
	float	θ;
	float	φ;

	θ = (M_PI * 2) / (map->limits.coords[X] - 1);
	φ = M_PI / (map->limits.coords[Y]);
	map->radius = map->limits.coords[X] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[LONG] = -(map->points[i].coords[X]) * θ;
		if (map->points[i].coords[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].coords[Y]) + \
			(map->limits.coords[Y] / 2)) * φ - 0.5 * φ;
		else
			map->points[i].polar[LAT] = (map->points[i].coords[Y] + \
			(map->limits.coords[Y] / 2) - 1) * φ + 0.5 * φ;
		i++;
	}
}
