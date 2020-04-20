##
## EPITECH PROJECT, 2019
## Makefile ASM
## File description:
## Compiles c files with libs into the asm program
##

MAIN			=	main.c

SRC_STATIC		=	static/print_asm_usage.c	\
					static/op.c					\

COMPLETE_SRC	=	$(SRC_STATIC)

SRC_TESTS		=	\

VPATH			=	/usr/local/lib/

NAME			=	asm

CFLAGS			=	-Wall -Wextra

CPPFLAGS		=	-I./../include/asm/ -I./../include/libmy/

LDFLAGS			=	-L./../lib/

LDLIBS			+=	-lmy

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./../lib/my
	$(CC) -o $@ $(MAIN) $(COMPLETE_SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug:
	$(MAKE) -C ./../lib/my
	$(CC) -g -o $@ $(MAIN) $(COMPLETE_SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:
	$(MAKE) -C ./../lib/my
	$(CC) -o $@ $(COMPLETE_SRC) $(SRCTESTS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -lcriterion --coverage
	./$@
	$(RM) $@

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) tests_run
	$(RM) *.gcda *.gcno
	$(RM) vgcore.*

fclean:	clean
	$(RM) $(NAME)
	$(RM) debug
	$(MAKE) fclean -sC ./../lib/my

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re