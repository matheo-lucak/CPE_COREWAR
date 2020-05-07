##
## EPITECH PROJECT, 2018
## task01
## File description:
## task01
##

CFLAGS		=

CPPFLAGS	=	-I../include

CRI_FLAGS	=	-lcriterion --coverage

SRC_MY		=	my_atoi.c					\
				my_cmalloc.c				\
				my_memcpy.c					\
				my_memset.c					\
				my_put_signed_long_base.c	\
				my_putchar.c				\
				my_putstr.c					\
				my_puttab.c					\
				my_read_file.c				\
				my_read_stdin.c				\
				my_realloc_tab.c			\
				my_sfree.c					\
				my_strcmp.c					\
				my_strconcat.c				\
				my_strdup.c					\
				my_strdup_until.c			\
				my_strncmp.c				\
				my_strncpy.c				\
				my_strlen.c					\
				my_strlen_until.c			\
				my_strndup.c				\
				my_swap_int_endian.c		\
				my_tablen.c

SRC_MY_PATH	=	$(addprefix ./my/,$(SRC_MY))

SRC		=	$(SRC_MY_PATH)

OBJ		=	$(SRC:.c=.o)

TEST_NAME	=	tests_run

TEST_SRC	=

TEST_SRC_PATH	=	$(addprefix ../tests/,$(TEST_SRC))

NAME		=	libmy.a

all:			$(NAME)

$(NAME):		$(OBJ)
			ar rc -o $(NAME) $(OBJ)

$(TEST_NAME):		all
			gcc -o $(TEST_NAME) $(SRC) $(TEST_SRC_PATH) $(CRI_FLAGS)	\
			-I../include/

clean:
			rm -f $(OBJ) *.gcno *.gcda

fclean: 		clean
			rm -f $(NAME)
			rm -f $(TEST_NAME)

re:			fclean all

auteur:
			echo $(USER) > auteur

.PHONY:			all $(NAME) clean fclean re auteur
