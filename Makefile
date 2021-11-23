# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syolando <syolando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 12:23:10 by syolando          #+#    #+#              #
#    Updated: 2021/10/27 15:10:12 by syolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_bzero.c \
					ft_calloc.c \
					ft_itoa.c \
					ft_isalnum.c \
					ft_isprint.c \
					ft_memcmp.c \
					ft_putchar_fd.c \
					ft_split.c \
					ft_strlen.c \
					ft_strlcat.c \
					ft_strncmp.c \
					ft_substr.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_memcpy.c \
					ft_putendl_fd.c \
					ft_strchr.c \
					ft_strlcpy.c \
					ft_strnstr.c \
					ft_tolower.c \
					ft_isascii.c \
					ft_toupper.c \
					ft_isdigit.c \
					ft_memchr.c \
					ft_memset.c \
					ft_putstr_fd.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_memmove.c \
					ft_strdup.c \
					ft_strmapi.c \
					ft_putnbr_fd.c \
					ft_strrchr.c \
					ft_striteri.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstnew.c \
					ft_lstsize.c \
					ft_putunsignedint_fd.c \
					ft_putnbr_hex.c \
					ft_put_void_ptr.c \
					ft_printf.c

OBJS			= $(SRCS:.c=.o)
D_FILE			= $(OBJS:.o=.d)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

%.o :			%.c
					$(CC) $(CFLAGS) -c  $< -o $@ -MD

all: 			$(NAME)

$(NAME): 		$(OBJS) libft.h
					ar rcs $(NAME) $?

clean:
					$(RM) $(OBJS) $(BONUS_OBJS) $(D_FILE)
				

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
