/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:28:43 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:12:18 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

# include "fdf.h"

int		draw_line(t_data *data, t_point start, t_point end);
void	draw_dot(t_data *data, t_point point, int radius);
int		gradient(int groundcolor, int topcolor, int len, int point);
int		my_putpixel(t_data *data, t_point pixel);
void	apply_shadow(t_point *points, int len);
#endif