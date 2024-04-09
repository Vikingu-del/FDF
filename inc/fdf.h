/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:48:46 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:16:32 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdbool.h>
# include "defines.h"
# include "control_keys.h"
# include "control_mouse.h"
# include "control_utils.h"
# include "draw_utils.h"
# include "errors.h"
# include "geometry.h"
# include "lib/get_next_line/get_next_line.h"
# include "map_utils.h"
# include "map.h"
# include "matrix.h"
# include "utils.h"
# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <strings.h>
# include <fcntl.h>
# ifdef __APPLE__
#  include "../lib/mlx_mac/mlx.h"
#  include "keycodes_mac.h"
#  define PLATFORM "mac"
# else
#  include "../lib/mlx_linux/mlx.h"
#  include "keycodes_linux.h"
#  define PLATFORM "linux"
# endif

#endif