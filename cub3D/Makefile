# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthomas <rthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 12:49:39 by rthomas           #+#    #+#              #
#    Updated: 2023/01/11 17:01:30 by rthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CFLAGS = -Wall -Wextra -Werror 

SOURCES =	main.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c 

			

OBJS = $(SOURCES:.c=.o)

all:		libft $(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) $(OBJS) ./libft/libft.a -lmlx -framework OpenGL -framework Appkit -o $(NAME)

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