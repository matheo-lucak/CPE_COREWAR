##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

MAIN				=	src/main.c

SRC_LINKING 		=

SRC_PARSING			=

SRC_QUEUE			=

SRC_WRITING			=

SRC					= $(SRC_LINKING) $(SRC_PARSING) $(SRC_QUEUE) $(SRC_WRITING)

OBJ					=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 				=	asm

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/ -I./../include

LDFLAGS				=	-L./lib/

override LDLIBS		+= 	-lmy

LIB 				= lib/libmy.a

all:				$(NAME)

$(NAME):			$(LIB) $(OBJ)
					$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIB):
					$(MAKE) -C lib/my

debug:				CPPFLAGS += -g
debug:				$(LIB)
					$(CC) -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:			LDLIBS += -lcriterion --coverage
tests_run:			CFLAGS += --coverage
tests_run:			$(LIB)
					$(CC) -o $@ $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
					./$@
					mv *.gc* tests/
					$(RM) $@

clean:
					$(RM) $(OBJ)
					$(MAKE) -C lib/my clean

fclean:				clean
					$(RM) $(NAME)
					$(MAKE) -C lib/my fclean

re:			 		fclean all

.NOTPARALLEL:
.PHONY:				debug all clean fclean re tests_run
