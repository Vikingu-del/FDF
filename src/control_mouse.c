/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:06:48 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/10 13:19:03 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
*	This function handle every time the mouse is moved
*/

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	if (data->keys.b_mouse_l)
	{
		angle(&data->map.ang[X], (int)data->keys.l_click.cords[Y] - y);
		angle(&data->map.ang[Y], (int)data->keys.l_click.cords[X] - x);
		data->keys.l_click.cords[X] = x;
		data->keys.l_click.cords[Y] = y;
		draw_map(data, FREE);
	}
	if (data->keys.b_mouse_r)
	{
		data->map.src.cords[X] -= ((int)data->keys.r_click.cords[X] - x);
		data->map.src.cords[Y] -= ((int)data->keys.r_click.cords[Y] - y);
		data->map.src.cords[Z] = 0;
		data->keys.r_click.cords[X] = x;
		data->keys.r_click.cords[Y] = y;
		draw_map(data, FREE);
	}
	return (0);
}

/* 
*	This function handle every time a mouse button is relased
*/

int	mouse_release(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 1)
		data->keys.b_mouse_l = 0;
	#ifdef __APPLE__
    if (button == 2)
	#else
		if (button == 3)
	#endif
			data->keys.b_mouse_r = 0;
	return (0);
}

/* 
*	This function handle every time a mouse button is pressed
*/

int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
	{
		data->keys.b_mouse_l = 1;
		data->keys.l_click.cords[X] = x;
		data->keys.l_click.cords[Y] = y;
	}
	#ifdef __APPLE__
    if (button == 2)
	#else
		if (button == 3)
	#endif
		{
			data->keys.b_mouse_r = 1;
			data->keys.r_click.cords[X] = x;
			data->keys.r_click.cords[Y] = y;
		}
	if (button == 5)
	{
		if (data->map.scale > 2)
			data->map.scale = data->map.scale / 1.5;
	}
	if (button == 4)
		data->map.scale = data->map.scale * 1.5;
	draw_map(data, FREE);
	return (0);
}
