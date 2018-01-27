# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gficara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:25:41 by gficara           #+#    #+#              #
#    Updated: 2018/01/27 18:31:54 by gficara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g

CC = gcc

INC = -I includes

SRC = libft/ft_abs.c \
		libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_count_if.c \
		libft/ft_foreach.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isint.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_lstadd.c \
		libft/ft_lstdel.c \
		libft/ft_lstdelone.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		libft/ft_lstnew.c \
		libft/ft_memalloc.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memdel.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putnbrendl.c \
		libft/ft_putnbrendl_fd.c \
		libft/ft_putstr.c \
		libft/ft_putnstr.c \
		libft/ft_putstr_fd.c \
		libft/ft_strcat.c \
		libft/ft_strchr.c \
		libft/ft_strchrnul.c \
		libft/ft_strclr.c \
		libft/ft_strcmp.c \
		libft/ft_strcpy.c \
		libft/ft_strdel.c \
		libft/ft_strdup.c \
		libft/ft_strequ.c \
		libft/ft_striter.c \
		libft/ft_striteri.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlen.c \
		libft/ft_strmap.c \
		libft/ft_strmapi.c \
		libft/ft_strncat.c \
		libft/ft_strncmp.c \
		libft/ft_strncpy.c \
		libft/ft_strnequ.c \
		libft/ft_strnew.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strsplit.c \
		libft/ft_strstr.c \
		libft/ft_strsub.c \
		libft/ft_strtolower.c \
		libft/ft_strtoupper.c \
		libft/ft_strtrim.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_sfstrjoin.c \
		libft/ft_sqrt.c \
		libft/ft_lstiso.c \
		libft/ft_lstcnt.c \
		libft/get_next_line.c \
		libft/ft_swap.c \
		sources/ft_printf.c \
		sources/pr_fun1.c \
		sources/pr_fun2.c \
		sources/pr_fun3.c \
		sources/pr_fun4.c \
		sources/pr_str.c \
		sources/ft_itoa_base.c \
		sources/ft_itoa_base_u.c \
		sources/ft_abs_base.c \
		sources/putuspecstr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) Makefile
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Creating libftprintf.a"

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean :
	@rm -rf $(OBJ)
	@echo "Removing libftprintf.a objects"

fclean : clean
	@rm -rf $(NAME)
	@echo "Removing libftprintf.a"

re: fclean all
