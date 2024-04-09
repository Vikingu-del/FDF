# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:45:00 by eseferi           #+#    #+#              #
#    Updated: 2024/04/09 21:36:15 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME			:= fdf

SRC_DIR			:= src/
OBJ_DIR			:= obj/
CC				:= gcc
CFLAGS			:= -g -O3 -Wall -Werror -Wextra
#FSANITIZE		:= -fsanitize=address -g3
FSANITIZE		:= 
NOFLAGS			:= -g
RM				:= rm -f

INC				:= inc/
LIB				:= lib/
PRINTF_DIR		:= $(LIB)ft_printf/
PRINTF			:= $(PRINTF_DIR)libftprintf.a

UNAME_S := $(shell uname -s)
# macOS
ifeq ($(UNAME_S),Darwin)
MLX_DIR			:= $(LIB)mlx_mac/
MLX_FILE		:= $(MLX_DIR)libmlx.a
LDFLAGS			:= -L$(MLX_DIR) -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit -lX11

# Linux
else
MLX_DIR			:= $(LIB)mlx_linux/
MLX_FILE		:= $(MLX_DIR)libmlx.a
LDFLAGS			:= -L$(MLX_DIR) -L /usr/lib/x86_64-linux-gnu/ -lmlx -lXext -lX11 -lm -lbsd
endif

LIBFT_DIR		:= $(LIB)ft_printf/$(LIB)libft/
LIBFT			:= $(LIBFT_DIR)libft.a
HEADER			:= -I. \
					-I$(INC) \
					-I$(PRINTF_DIR) \
					-I$(PRINTF_DIR)inc/ \
					-I$(LIBFT_DIR) \
					-I$(LIBFT_DIR)inc/ \
					-I$(LIB)get_next_line/ \
					-I$(MLX_DIR)

MAKE_LIB		:= make --no-print-directory -s -C

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	= $(wildcard $(SRC_DIR)*.c)

SRC			= 	$(SRC_FILES)
OBJ			= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))
DEPS		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INC), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	makelibs
		@$(MAKE) $(NAME)

makelibs:	
	@$(MAKE_LIB) $(PRINTF_DIR)
	@$(MAKE_LIB) $(LIBFT_DIR)
	@$(MAKE_LIB) $(MLX_DIR)

-include 	${DEPS}
$(NAME):	$(OBJ)		
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(LIBFT) $(LDFLAGS) -o $(NAME)		
			@echo "👉 $(MAGENTA)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(LDFLAGS) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN)🐣 FDF compiled!$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "🍳 $(CYAN)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(HEADER) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"	

$(LIBFT):
	@make -C $(LIBFT_DIR)
	

$(MLX):
	@make -C $(MLX_DIR)
	@echo "$(GREEN)MLX compiled!$(DEF_COLOR)"			

clean:
			@make clean -sC $(PRINTF_DIR)
			@echo "$(CYAN)ft_printf object and dependency files cleaned.$(DEF_COLOR)"
			@make clean -C $(MLX_DIR)
			@echo "$(CYAN)MLX object files cleaned.$(DEF_COLOR)"	
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
			$(RM) -f $(MLX_DIR)libmlx.a
			@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
			$(RM) -f $(LIBFT_DIR)libft.a
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm