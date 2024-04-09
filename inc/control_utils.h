/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:33:28 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 18:10:19 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_UTILS_H
# define CONTROL_UTILS_H

# include "fdf.h"

void	control_angle(int key, t_data *data);
void	angle(float *ang, float value);
void	apply_color_scheme(t_map *map);
int		close_program(void *param);
void	exit_with_error(char *s);
void	control_colorscheme(int key, t_map *map);

#endif