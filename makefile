# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 18:01:34 by ael-kace          #+#    #+#              #
#    Updated: 2023/01/28 19:16:17 by ael-kace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

SRCS =  check_map.c check_map1.c check_map2.c check_map3.c \
		check_stuff.c ft_move.c ft_printf.c get_next_line.c \
		get_next_line_utils.c so_long.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CC_FLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

all :  $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(CC_FLAGS) $(OBJS) -o $(NAME)
		
%.o: %.c $(HEADER)
	$(CC) -c $<

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re