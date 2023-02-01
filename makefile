# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 18:01:34 by ael-kace          #+#    #+#              #
#    Updated: 2023/02/01 12:34:41 by ael-kace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

SRCS =  check_map.c check_map1.c check_map2.c check_map3.c check_map4.c \
		check_stuff.c ft_move.c ft_printf.c get_next_line.c \
		get_next_line_utils.c so_long.c ft_strncmp.c valid_path.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

all :  $(NAME)

$(NAME): $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
		
%.o: %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $<

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re