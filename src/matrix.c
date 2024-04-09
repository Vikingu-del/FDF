/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:11:46 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:15:20 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// multiply the rotation matrix by the point to rotate it
t_point	point_mult_matrix(float matrix[3][3], t_point point)
{
	int		row_index;
	int		col_index;
	t_point	transed_point;

	transed_point = point;
	row_index = 0;
	while (row_index < 3)
	{
		transed_point.cords[row_index] = 0;
		transed_point.color = point.color;
		col_index = 0;
		while (col_index < 3)
		{
			transed_point.cords[row_index] += \
				matrix[row_index][col_index] * point.cords[col_index];
			col_index++;
		}
		row_index++;
	}
	return (transed_point);
}

// converts the angle from degrees to radians creates a matrix based on the 
// angle and multiplies the matrix by the point to rotate it around the x axis
void	rotate_x(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	x_rotation_matrix[3][3];

	rad = ang * M_PI / 180;
	init_matrix(x_rotation_matrix);
	x_rotation_matrix[X][X] = 1;
	x_rotation_matrix[Y][Y] = cos(rad);
	x_rotation_matrix[Y][Z] = -sin(rad);
	x_rotation_matrix[Z][Y] = sin(rad);
	x_rotation_matrix[Z][Z] = cos(rad);
	i = 0;
	while (i < len)
	{
		projection[i] = point_mult_matrix(x_rotation_matrix, points[i]);
		i++;
	}
}

// converts the angle from degrees to radians creates a matrix based on the 
// angle and multiplies the matrix by the point to rotate it around the y axis
void	rotate_y(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	y_rotation_matrix[3][3];

	rad = ang * M_PI / 180;
	init_matrix(y_rotation_matrix);
	y_rotation_matrix[X][X] = cos(rad);
	y_rotation_matrix[X][Z] = sin(rad);
	y_rotation_matrix[Y][Y] = 1;
	y_rotation_matrix[Z][X] = -sin(rad);
	y_rotation_matrix[Z][Z] = cos(rad);
	i = 0;
	while (i < len)
	{
		projection[i] = point_mult_matrix(y_rotation_matrix, points[i]);
		i++;
	}
}

// converts the angle from degrees to radians creates a matrix based on the 
// angle and multiplies the matrix by the point to rotate it around the z axis
void	rotate_z(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	z_rotation_matrix[3][3];

	rad = ang * M_PI / 180;
	init_matrix(z_rotation_matrix);
	z_rotation_matrix[X][X] = cos(rad);
	z_rotation_matrix[X][Y] = -sin(rad);
	z_rotation_matrix[Y][X] = sin(rad);
	z_rotation_matrix[Y][Y] = cos(rad);
	z_rotation_matrix[Z][Z] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = point_mult_matrix(z_rotation_matrix, points[i]);
		i++;
	}
}

// Calculate len "points" of the array to orto projection
// and store in "projection" array.
void	orthographic_projection(t_point *points, t_point *projection, int len)
{
	int		i;
	float	projection_matrix[3][3];

	init_matrix(projection_matrix);
	projection_matrix[X][X] = 1;
	projection_matrix[Y][Y] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = point_mult_matrix(projection_matrix, points[i]);
		i++;
	}
}
