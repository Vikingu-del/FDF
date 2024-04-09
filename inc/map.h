/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:56:47 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 18:12:58 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fdf.h"

/* DEFINES NORMINETTE REFUSED
#define XCENTER				((WINX - MENU_WIDTH) / 2) + MENU_WIDTH
#define YCENTER				WINY / 2
*/

int		draw_map(t_data *data, int should_fit_window);
void	load_map(t_map *map, char *file);
void	generate_background(t_data *data, int backcolor, int menucolor);
void	draw_menu(t_data *data);
void	load_color(int max, int min, t_point *point, t_palette palette);
void	generate_stars(t_data *data);
#endif