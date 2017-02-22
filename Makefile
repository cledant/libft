# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/02/22 13:06:54 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O2 -fsigned-char

OBJ_DIR_NAME = obj

INCLUDES = ./includes

INCLUDES_PRINTF = ./ft_printf/includes

SRC_NAME = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_puts.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
			ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
			ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
			ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
			ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
			ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			ft_abs.c ft_isodd.c ft_iseven.c ft_putnbrendl.c ft_putnbrendl_fd.c \
			ft_lstpushback.c ft_putendln.c ft_putstrn.c get_next_line.c \
			ft_isspace.c ft_max.c ft_can_be_atoi.c ft_strsplit_allspace.c \
			ft_lstread_fd.c ft_lstcount_non_zero_size_node.c ft_lstcount_node.c \
			ft_round_double.c ft_btree_new.c ft_btree_delone.c \
			ft_btree_del_all_node.c ft_btree_add_node.c \
			ft_btree_apply_reverse_infix.c ft_btree_apply_infix.c \
			ft_btree_apply_postfix.c ft_strchrncmp.c ft_is_str_a_number.c \
			ft_char2_index_size.c ft_strdel_char2.c ft_strdup_char2.c \
			ft_strcpy_char2.c ft_strnew_char2.c ft_putendl_char2.c \
			ft_switch_char2.c ft_switch_str.c ft_is_str_only_spaces.c \
			ft_is_str_alphanum.c ft_lstfree_malloc.c ft_strtoupper.c \
			ft_strtolower.c ft_wcharlen.c ft_wputchar.c ft_wputstr.c \
			ft_wlen_strlen.c ft_wstrlen.c ft_wstrnew.c ft_wstrcpy.c ft_wstrdup.c \
			ft_wstrjoin.c ft_can_be_atoi_len.c ft_is_not_int.c \
			ft_tputchar.c ft_lstneworpushback.c ft_strnlen.c ft_strconcat.c

SRC_NAME_PRINTF =	ft_printf.c ft_printf_is_converter.c ft_printf_analyse_string.c \
			ft_printf_is_flag.c ft_printf_is_modifier.c ft_printf_fill_converter.c \
			ft_printf_parse_type.c ft_printf_fill_flag.c ft_printf_print_args.c \
			ft_printf_fill_modifier.c ft_printf_setup_data.c ft_printf_init_data.c \
			ft_printf_d.c ft_printf_u.c ft_printf_hex_converter_long_int.c \
			ft_printf_itoa_unsigned.c ft_printf_o.c ft_printf_octal_converter.c \
			ft_printf_xx.c ft_printf_hex_converter.c ft_strtoupper.c \
			ft_printf_ld.c ft_printf_itoa_long_int.c ft_printf_lxx.c \
			ft_printf_lo.c ft_printf_octal_converter_long_int.c ft_printf_lu.c \
			ft_printf_itoa_unsigned_long_int.c \
			ft_printf_s.c ft_printf_c.c ft_printf_ls.c \
			ft_printf_lc.c ft_printf_lld.c \
			ft_printf_llo.c ft_printf_llu.c ft_printf_llxx.c \
			ft_printf_hex_converter_long_long_int.c \
			ft_printf_octal_converter_long_long_int.c \
			ft_printf_itoa_long_long_int.c ft_printf_itoa_unsigned_long_long_int.c \
			ft_printf_hd.c ft_printf_ho.c ft_printf_hu.c ft_printf_hxx.c \
			ft_printf_hhd.c ft_printf_hho.c ft_printf_hhu.c \
			ft_printf_hhxx.c ft_printf_p.c ft_printf_add_front_string.c \
			ft_printf_chain_modifier.c ft_printf_chain_modifier_ull.c \
			ft_printf_mod_precision.c ft_printf_mod_rm_preci.c ft_printf_mod_size.c\
			ft_printf_mod_precision_str_simple.c \
			ft_wlen_strnlen.c ft_printf_mod_size_w.c ft_wlen_strcpy.c \
			ft_printf_chain_modifier_w.c \
			ft_printf_mod_precision_str_w.c ft_printf_mod_size_zero.c \
			ft_printf_mod_size_zero_hex.c ft_printf_mod_size_zero_w.c \
			ft_printf_add_n_behind_string.c ft_str_front_n_remove.c \
			ft_printf_mod_size_zero_string.c \
			ft_printf_add_n_behind_w_string.c ft_printf_other.c \
			ft_printf_length_0.c ft_printf_length_1.c ft_printf_length_2.c \
			ft_printf_length_minus_1.c ft_printf_length_minus_2.c \
			ft_printf_set_flag_zero_sc.c ft_printf_init_analyse.c \
			ft_printf_length_j.c ft_printf_length_z.c

SRC_PATH = ./srcs

SRC_PATH_PRINTF = ./ft_printf/srcs

OBJ =	$(SRC_NAME:%.c=$(OBJ_DIR_NAME)/%.o)

OBJ_PRINTF =	$(SRC_NAME_PRINTF:%.c=$(OBJ_DIR_NAME)/%.o)

NAME = libft.a

all : $(NAME)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

libftprintf : $(OBJ_DIR_NAME) $(OBJ) $(OBJ_PRINTF)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(NAME) : $(OBJ_DIR_NAME) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR_NAME)/%.o : $(SRC_PATH)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES)

$(OBJ_DIR_NAME)/%.o : $(SRC_PATH_PRINTF)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_PRINTF)

clean :
	rm -rf $(OBJ_DIR_NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all

re_libftprintf : fclean libftprintf

.PHONY : all clean fclean re libftprintf re_libftprintf
