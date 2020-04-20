##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## processes compilation for this lib
##

SRC			=	./my_isnum.c						\
				./my_isalpha.c						\
				./my_isalphanum.c					\
				./my_str_is_alphanum.c				\
				./my_strlen.c						\
				./my_strlen_until_list_c.c			\
				./my_strnlen.c						\
				./my_strcpy.c						\
				./my_arrcpy.c						\
				./my_append_to_array.c				\
				./my_strdup.c						\
				./my_strdup_until_list_c.c			\
				./my_strndup.c						\
				./my_str_eq_str.c					\
				./my_str_eq_str_n.c					\
				./my_arr_eq_arr.c					\
				./my_mass_strcmp.c					\
				./my_parse_str.c					\
				./my_memset.c						\
				./my_nb_char_in_str.c				\
				./my_strcat.c						\
				./my_is_char_in_str.c				\
				./my_arrlen.c						\
				./my_arrdup.c						\
				./my_free_2d.c						\
				./get_next_line.c					\
				./my_putchar.c						\
				./my_putstr.c						\
				./my_put_nbr.c						\
				./my_put_nbr_u.c					\
				./my_put_nbr_s.c					\
				./my_put_nbr_su.c					\
				./my_put_nbr_l.c					\
				./my_put_nbr_ll.c					\
				./my_put_nbr_lu.c					\
				./my_put_nbr_llu.c					\
				./my_loop_in_str_until_c.c			\
				./my_loop_in_str_until_list_c.c		\
				./my_loop_in_str_while_c.c			\
				./my_loop_in_str_while_list_c.c		\
				./my_arr_show.c						\
				./my_strdup_list_i.c				\


SRCMYPRINTF	=	./my_printf/my_printf.c				\
				./my_printf/flag_checkers.c			\
				./my_printf/get_flag.c				\
				./my_printf/redirect_putchar.c		\
				./my_printf/redirect_put_nbr.c		\
				./my_printf/redirect_short.c		\
				./my_printf/redirect_long.c			\
				./my_printf/redirect_percent.c		\
				./my_printf/redirect_lower_upper.c	\
				./my_printf/redirect_hashtag.c		\
				./my_printf/redirect_add_ptr.c		\
				./my_printf/my_flag_cmp.c

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./../../include/libmy/

OBJ			=	$(SRC:.c=.o) $(SRCMYPRINTF:.c=.o)

NAME		=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.NOTPARALLEL:
.PHONY: all clean fclean re