# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 12:49:39 by rthomas           #+#    #+#              #
#    Updated: 2023/04/08 18:28:26 by romainthoma      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CFLAGS = -Wall -Wextra -Werror 

SOURCES =	source/main.c \
			source/raycasting_part.c \
			source/parsing_main.c \
			source/parsing_arg.c \
			source/parsing_wall_color.c \
			source/parsing_player.c \
			source/parsing_map.c \
			source/mouvement.c \
			source/minimap.c \
			source/random.c \
			source/texture.c \
			source/innit.c \
			source/read_file.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

MLX				= libmlx.dylib

OBJS = $(SOURCES:.c=.o)

all:		libft $(NAME)

$(NAME):	$(MLX) $(OBJS)
			gcc $(CFLAGS) $(OBJS) ./libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

libft:
			make -C ./libft

clean:
			rm -f $(OBJS)
			#make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			#make fclean -C ./libft

norme:
			norminette $(SRCS)

re:			fclean all

.PHONY:		re clean fclean all libft