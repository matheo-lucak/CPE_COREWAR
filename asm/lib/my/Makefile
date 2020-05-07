##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

SRC			=	my_arrlen.c				\
				my_count_char.c			\
				my_getnbr.c 			\
				my_hay_needle.c			\
				my_int_to_str.c			\
				my_is.c					\
				my_mass_strcat.c		\
				my_mass_strcmp.c		\
				my_memset.c				\
				my_pow.c				\
				my_put_address.c		\
				my_put_char.c			\
				my_put_int.c			\
				my_put_long_long.c		\
				my_put_long.c			\
				my_put_short.c			\
				my_put_uchar.c			\
				my_put_uint.c			\
				my_put_ulong_long.c		\
				my_put_ulong.c			\
				my_put_ushort.c			\
				my_putchar.c			\
				my_putstr.c				\
				my_show_word_array.c	\
				my_skip.c				\
				my_str_is.c				\
				my_str_to_word_array.c	\
				my_strcat.c				\
				my_strcmp.c				\
				my_strcpy.c				\
				my_strdup.c				\
				my_strcmp.c				\
				my_strcpy.c				\
				my_strdup.c				\
				my_strlen.c				\
				my_strncat.c			\
				my_strncmp.c			\
				my_strncpy.c			\
				my_strdup_word.c		\
				my_strndup.c			\
				my_strstr.c				\
				my_find_char.c			\
				my_memcpy.c				\
				my_free_arr.c			\
				get_next_line.c

PRINTF_SRC	=	my_printf/my_printf.c		\
				my_printf/my_printf_init.c	\
				my_printf/tool_cast1.c		\
				my_printf/tool_flag1.c		\
				my_printf/tool_flag2.c		\
				my_printf/tool_flag3.c		\
				my_printf/tool_flagtool.c	\

OBJ			=	$(SRC:.c=.o)

PRINTF_OBJ	=	$(PRINTF_SRC:.c=.o)

ARFLAGS 	=	rc

NAME		=	libmy.a

CPPFLAGS	=	-I./include/

NAME_MY_H	=	my.h


all:		$(NAME)

$(NAME):	$(OBJ) $(PRINTF_OBJ)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(PRINTF_OBJ)
			cp $(NAME) ./../$(NAME)
			cp ./include/$(NAME_MY_H) ./../../include/$(NAME_MY_H)

clean:
			$(RM) $(OBJ) $(PRINTF_OBJ)

fclean: 	clean
			$(RM) ../../include/$(NAME_MY_H)
			$(RM) ../$(NAME)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
