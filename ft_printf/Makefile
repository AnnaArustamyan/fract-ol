# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarustam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 21:20:54 by aarustam          #+#    #+#              #
#    Updated: 2024/04/05 21:20:56 by aarustam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -rf

AR	= ar rcs

SRCS = ft_printf.c print_disc.c print_unsigned.c print_ptr.c print_hex.c

OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re:	fclean all

.PHONY: all clean fclean re
