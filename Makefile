# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:30:42 by jpoulvel          #+#    #+#              #
#    Updated: 2019/03/26 15:05:45 by pchambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/main.c \
		srcs/parser.c \
		srcs/coord.c \
		srcs/higher_pos.c \
		srcs/lower_pos.c \
		srcs/bresenham.c \
		srcs/draw.c \
		srcs/events.c \
		srcs/color.c \
		srcs/extra_functions.c \

OBJ = $(SRCS:.c=.o)

LIB_DIR = X-Libft
MLX_DIR = MiniLibX

INCL =$(LIB_DIR)/libft.a \
		$(MLX_DIR)/libmlx.a \

FRMWRK = -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -I $(FRMWRK) $(INCL)

all: LIB $(NAME)

LIB:
	@cd $(LIB_DIR) ; $(MAKE) -f Makefile
	@cd $(MLX_DIR) ; $(MAKE) -f Makefile

$(NAME): LIB $(OBJ)
	@gcc $(FLAGS) $(LIB) -o fdf $(OBJ)

clean: 
	rm -f $(OBJ)
	cd $(LIB_DIR) ; $(MAKE) clean
	cd $(MLX_DIR) ; $(MAKE) clean

fclean: clean
	rm -f a.out $(NAME)
	cd $(LIB_DIR) ; $(MAKE) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
