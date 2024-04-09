/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:39:54 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 21:12:11 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "fdf.h"

# define WINX 1920	
# define WINY 1080

# define X 0
# define Y 1
# define Z 2

# define LAT 0
# define LONG 1

# define RED			0xc1272d
# define GREEN			0x33cc55
# define FUCHSIA		0xff255c
# define BLUE			0x1B8EFA
# define LIGHT_BLUE		0x0000FF
# define BLACK			0x151515
# define GRAY			0xBBBBBB
# define PURPLE			0x9A1F6A
# define DARK_RED		0xC2294E
# define ORANGE			0xEC4B27
# define YELLOW_ORANGE	0xEF8633
# define YELLOW			0xF3AF3D

# define DEFAULT_COLOR		YELLOW_ORANGE
# define BOTTOM_COLOR		BLUE
# define TOP_COLOR			DARK_RED
# define GROUND_COLOR		YELLOW
# define BACK_COLOR			BLACK
# define MENU_COLOR			0x202020
# define TEXT_COLOR			0xEAEAEA	
# define NUMBER_COLOR		YELLOW

# define MENU_WIDTH			370
# define FIT_MARGIN			50

# define FIT				1
# define FREE				0

// A structure to manipulate the points.
typedef struct s_point {
	float	cords[3];
	int		color;
	int		hex_color;
	bool	paint;
	float	polar[2];
}	t_point;

// A structure to manipulate the colors.
typedef struct m_palette {
	int	topcolor;
	int	groundcolor;
	int	bottomcolor;
	int	backcolor;
	int	menucolor;
}	t_palette;

// A structure to translate the picture to bitmap format.
typedef struct s_picture {
	void	*img;
	char	*buffer;
	int		bitxpixel;
	int		lines;
	int		endian;
}	t_picture;

// A structure to manipulate the variables.
typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

// A structure to manipulate the keys.
typedef struct s_keys {
	bool			b_mouse_l;
	bool			b_mouse_r;
	bool			b_keyctrl;
	t_point			l_click;
	t_point			r_click; 
}	t_keys;

// A structure to manipulate the map.
typedef struct m_map {
	t_point			*points;
	t_point			limits;
	t_point			src;
	t_palette		colors;
	char			*content;
	char			**lines;
	int				zmin;
	float			ang[3];
	float			z_scale;
	float			scale;
	int				len;
	float			curve_range;
	int				renders;
	bool			wires;
	bool			dots;
	bool			pluslines;
	bool			sphere;
	bool			stars;
	bool			shadows;
	double			performance;
	float			ratio;
	float			radius;
}	t_map;

// All data in one structure.
typedef struct s_data {
	t_vars		vars;
	t_picture	picture;
	t_map		map;
	t_keys		keys;
}	t_data;

# define DEF_COLOR	"\033[0;39m"
# define SH_GRAY	"\033[0;90m"
# define SH_RED		"\033[0;91m"
# define SH_GREEN	"\033[0;92m"
# define SH_YELLOW	"\033[0;93m"
# define SH_BLUE	"\033[0;94m"
# define SH_MAGENTA	"\033[0;95m"
# define SH_CYAN	"\033[0;96m"
# define SH_WHITE	"\033[0;97m"
# define SH_KNR		"\x1B[0m"
# define SH_KRED	"\x1B[31m"
# define SH_KGRN	"\x1B[32m"
# define SH_KYEL	"\x1B[33m"
# define SH_KBLU	"\x1B[34m"
# define SH_KMAG	"\x1B[35m"
# define SH_KCYN	"\x1B[36m"
# define SH_KWHT	"\x1B[37m"
# define U_ORANGE	"\033[48:5:208m"
# define U_WHITE	"\033[37;7:208m"
# define U_YELLOW	"\033[33;7:208m"
# define U_BLUE		"\033[34;7:208m"

#endif