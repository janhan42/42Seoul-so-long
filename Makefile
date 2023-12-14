# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 12:24:28 by janhan            #+#    #+#              #
#    Updated: 2023/12/14 16:47:41 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long

LIBFT		=		libft/libft.a
HEAD		=		includes/so_long.h

SRCS		=		srcs/so_long.c
OBJS		=		$(SRCS:.c=.o)

CC			=		cc
CFLAGS		=		-Wall -Wextra -Werror
MLXFLAGS	=		-L./mlx -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft fclean
	rm -fr $(NAME)

re :
	$(MAKE) -C libft fclean
	make fclean
	make all

.PHONY = make all clean fclean re
