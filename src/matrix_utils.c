/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 01:10:38 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 20:31:44 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "fdf.h"

// void	orto_projection(t_point *points, t_point *projection, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		projection[i].coords[X] = points[i].coords[X];
// 		projection[i].coords[Y] = points[i].coords[Y];
// 		i++;
// 	}
// }

// void    rotate_x(t_point *points, t_point *projection, float ang, int len)
// {
//     int	i;
//     float	rot_matrix[3][3];

//     i = 0;
//     init_matrix(rot_matrix);
//     rot_matrix[1][1] = cos(ang);
//     rot_matrix[1][2] = -sin(ang);
//     rot_matrix[2][1] = sin(ang);
//     rot_matrix[2][2] = cos(ang);
//     while (i < len)
//     {
//         projection[i].coords[X] = points[i].coords[X] * rot_matrix[0][0] + \
//                                 points[i].coords[Y] * rot_matrix[0][1] + \
//                                 points[i].coords[Z] * rot_matrix[0][2];
//         projection[i].coords[Y] = points[i].coords[X] * rot_matrix[1][0] + \
//                                 points[i].coords[Y] * rot_matrix[1][1] + \
//                                 points[i].coords[Z] * rot_matrix[1][2];
//         projection[i].coords[Z] = points[i].coords[X] * rot_matrix[2][0] + \
//                                 points[i].coords[Y] * rot_matrix[2][1] + \
//                                 points[i].coords[Z] * rot_matrix[2][2];
//         i++;
//     }
// }

// void    rotate_y(t_point *points, t_point *projection, float ang, int len)
// {
//     int	i;
//     float	rot_matrix[3][3];

//     i = 0;
//     init_matrix(rot_matrix);
//     rot_matrix[0][0] = cos(ang);
//     rot_matrix[0][2] = sin(ang);
//     rot_matrix[2][0] = -sin(ang);
//     rot_matrix[2][2] = cos(ang);
//     while (i < len)
//     {
//         projection[i].coords[X] = points[i].coords[X] * rot_matrix[0][0] + \
//                                 points[i].coords[Y] * rot_matrix[0][1] + \
//                                 points[i].coords[Z] * rot_matrix[0][2];
//         projection[i].coords[Y] = points[i].coords[X] * rot_matrix[1][0] + \
//                                 points[i].coords[Y] * rot_matrix[1][1] + \
//                                 points[i].coords[Z] * rot_matrix[1][2];
//         projection[i].coords[Z] = points[i].coords[X] * rot_matrix[2][0] + \
//                                 points[i].coords[Y] * rot_matrix[2][1] + \
//                                 points[i].coords[Z] * rot_matrix[2][2];
//         i++;
//     }
// }

// void    rotate_z(t_point *points, t_point *projection, float ang, int len)
// {
//     int	i;
//     float	rot_matrix[3][3];

//     i = 0;
//     init_matrix(rot_matrix);
//     rot_matrix[0][0] = cos(ang);
//     rot_matrix[0][1] = -sin(ang);
//     rot_matrix[1][0] = sin(ang);
//     rot_matrix[1][1] = cos(ang);
//     while (i < len)
//     {
//         projection[i].coords[X] = points[i].coords[X] * rot_matrix[0][0] + \
//                                 points[i].coords[Y] * rot_matrix[0][1] + \
//                                 points[i].coords[Z] * rot_matrix[0][2];
//         projection[i].coords[Y] = points[i].coords[X] * rot_matrix[1][0] + \
//                                 points[i].coords[Y] * rot_matrix[1][1] + \
//                                 points[i].coords[Z] * rot_matrix[1][2];
//         projection[i].coords[Z] = points[i].coords[X] * rot_matrix[2][0] + \
//                                 points[i].coords[Y] * rot_matrix[2][1] + \
//                                 points[i].coords[Z] * rot_matrix[2][2];
//         i++;
//     }
// }
