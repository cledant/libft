# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/08/21 14:49:46 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O2 -fsigned-char

OBJ_DIR_NAME = obj

INCLUDES = ./includes

SRC_NAME = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
		ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
		ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_abs.c ft_isodd.c ft_iseven.c \
		ft_putnbrendl.c ft_putnbrendl_fd.c ft_lstpushback.c ft_putendln.c ft_putstrn.c \
		get_next_line.c ft_isspace.c ft_max.c ft_int_tab2_new.c ft_can_be_atoi.c \
		ft_strsplit_allspace.c ft_lstread_file.c ft_lstcount_non_zero_size_node.c \
		ft_lstcount_node.c ft_round_double.c ft_btree_new.c ft_btree_delone.c \
		ft_btree_del_all_node.c ft_btree_add_node.c ft_btree_apply_reverse_infix.c \
		ft_btree_apply_infix.c ft_btree_apply_postfix.c ft_strcmp_char_n_to_first.c \
		ft_free_content.c ft_is_str_a_number.c ft_char2_index_size.c \
		ft_strdel_char2.c ft_strdup_char2.c ft_strcpy_char2.c ft_strnew_char2.c \
		ft_putendl_char2.c ft_switch_char2.c ft_switch_str.c \
		ft_is_str_only_spaces.c ft_is_str_alphanum.c ft_lstfree_malloc.c \
		ft_strtoupper.c ft_strtolower.c ft_wcharlen.c ft_wputchar.c ft_wputstr.c \
		ft_wlen_strlen.c ft_wstrlen.c ft_wstrnew.c ft_wstrcpy.c ft_wstrdup.c \
		ft_wstrjoin.c ft_can_be_atoi_len.c ft_is_not_int.c gnl_prompt.c \
		ft_tputchar.c ft_lstnewpushback.c

SRC_PATH = ./srcs

OBJ =	$(SRC_NAME:%.c=$(OBJ_DIR_NAME)/%.o)

NAME = libft.a

all : $(OBJ_DIR_NAME) $(NAME)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR_NAME)/%.o : $(SRC_PATH)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES)

clean :
	rm -rf $(OBJ_DIR_NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
