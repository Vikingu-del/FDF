/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:23 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 18:13:24 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"

void	free_2darray(char **ptr);
void	print_nbr(t_data *data, int x, int y, int nbr);
void	print_str(t_data *data, int x, int y, char *str);
void	copy_map_points(t_point *map_points, t_point *projection, int len);
int		valid_pixel(t_point pixel);
int		modified_atoi(const char *str);
#endif