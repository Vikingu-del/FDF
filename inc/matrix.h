/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:11:13 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 20:11:45 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "fdf.h"

void	orto_projection(t_point *points, t_point *projection, int len);
void	rotate_x(t_point *points, t_point *projection, float ang, int len);
void    rotate_y(t_point *points, t_point *projection, float ang, int len);
void    rotate_z(t_point *points, t_point *projection, float ang, int len);
void	init_matrix(float matrix[][3]);
t_point	point_mult_matrix(float matrix[3][3], t_point point);
#endif