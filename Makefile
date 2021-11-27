# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syolando <syolando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 12:23:10 by syolando          #+#    #+#              #
#    Updated: 2021/11/25 14:36:00 by syolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strlen.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putunsignedint_fd.c \
			ft_putnbr_hex_fd.c \
			ft_put_void_ptr_fd.c \
			ft_printf.c

OBJS	=	$(SRCS:.c=.o)
D_FILE	=	$(OBJS:.o=.d)

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
HEADER	=	ft_printf.h

NAME	=	libftprintf.a

%.o		:	%.c
			$(CC) $(CFLAGS) -c  $< -o $@ -MD

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			ar rcs $(NAME) $?

clean	:
			$(RM) $(OBJS) $(BONUS_OBJS) $(D_FILE)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)

include		$(wildcard $(D_FILE))

.PHONY:		all clean fclean re bonus

