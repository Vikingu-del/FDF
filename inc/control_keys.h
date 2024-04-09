/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:28:54 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 18:10:27 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_KEYS_H
# define CONTROL_KEYS_H

# include "fdf.h"

int		key_press(int key, void *param);
int		key_release(int key, void *param);
#endif