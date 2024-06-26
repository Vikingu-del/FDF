/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:29:29 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 21:12:02 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_MOUSE_H
# define CONTROL_MOUSE_H

# include "fdf.h"

int		mouse_move(int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);
#endif