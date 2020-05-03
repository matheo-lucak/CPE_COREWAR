##
## EPITECH PROJECT, 2018
## task01
## File description:
## task01
##

CFLAGS		=

CPPFLAGS	=	-I../include

CRI_FLAGS	=	-lcriterion --coverage

SRC_MY		=

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
