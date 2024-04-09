/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:39:08 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 18:12:31 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "fdf.h"

void	traslate(t_point *points, t_point move, int len);
void	scale_map(t_point *points, int scale, int len);
void	isometric(t_map *map);
void	curving(t_point *points, int len, float curve_range);
void	parallel(t_map *map);
void	sphering(t_map *map, t_point *points);
void	cart_to_pol(t_map *map);
#endif