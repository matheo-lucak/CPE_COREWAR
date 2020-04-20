##
## EPITECH PROJECT, 2019
## task01
## File description:
## task01
##

CFLAGS			=	-W -Wall -Wextra

CPPFLAGS		=	-I./include/

CRI_FLAGS		=   -lcriterion --coverage

SRC_MAIN		=	src/main.c

SRC				=

SRC_PATH		=	$(addprefix ./src/,$(SRC))

TEST_SRC		=

TEST_SRC_PATH	=	$(addprefix ./tests/,$(TEST_SRC))

OBJ				=	$(SRC_MAIN:.c=.o)	\
					$(SRC_PATH:.c=.o)

TEST_NAME		=	tests_run

NAME			=	coeur_guerre

all:			relib $(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/ -lmy

relib:
				make re -C ./lib/

$(TEST_NAME):		clean relib
				gcc -o $(TEST_NAME) $(CRI_FLAGS) $(SRC_PATH) $(LIB_PATH) $(TEST_SRC_PATH) \
				-L./lib/ -lmy \
				./tests_run

clean:
				rm -f $(OBJ) *.gcno *.gcda
				make clean -C ./lib/

fclean:			clean
				rm -f $(NAME)
				rm -f $(TEST_NAME)
				make fclean -C ./lib/

re:				fclean all

auteur:
				echo $(USER) > auteur

.PHONY: 		all $(NAME) clean fclean re auteur
