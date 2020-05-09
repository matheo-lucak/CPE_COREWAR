##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

MAIN				=	src/main.c										\
						src/asm.c										\

OP					=	src/op.c

SRC_OPEN			=	src/open/get_file_name_from_path.c				\
						src/open/open_file_reader.c						\
						src/open/open_file_writer.c						\

SRC_LINKING 		=	src/linking/instruction/get_program_size.c		\
						src/linking/label/check_existing_label.c		\
						src/linking/label/get_label_address.c			\
						src/linking/label/link_labels.c					\

SRC_PARSING			=	src/parsing/body/instruction/fill_instruction.c	\
						src/parsing/body/instruction/fill_mnemonic.c	\
						src/parsing/body/instruction/fill_params.c		\
						src/parsing/body/instruction/param_errors.c		\
						src/parsing/body/instruction/param_is.c			\
						src/parsing/body/instruction/redirect_params.c	\
						src/parsing/body/label/fill_label.c				\
						src/parsing/body/label/is_label.c				\
						src/parsing/body/label/is_valid_label.c			\
						src/parsing/body/redirect_body.c				\
						src/parsing/header/fill_header.c				\
						src/parsing/header/is_header.c					\
						src/parsing/parsing_error.c						\
						src/parsing/parsing.c							\
						src/parsing/redirect_parsing.c					\

SRC_QUEUE			=	src/queue/dequeue.c								\
						src/queue/empty_queue.c							\
						src/queue/enqueue.c								\

SRC_WRITING			=	src/writing/write_body.c						\
						src/writing/write_header.c						\
						src/writing/writing.c							\

SRC					= $(SRC_LINKING) $(SRC_PARSING) $(SRC_QUEUE) $(SRC_WRITING) $(SRC_OPEN) $(OP)

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
					$(CC) -o $@ $(SRC) tests/test_*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
					./$@
					mv *.gc* tests/
					$(RM) $@

clean:
					$(RM) $(OBJ)
					$(MAKE) -C lib/my clean
					$(RM) *.gcda
					$(RM) *.gcno
					$(RM) tests/*.gcda
					$(RM) tests/*.gcno

fclean:				clean
					$(RM) $(NAME)
					$(MAKE) -C lib/my fclean

re:			 		fclean all

.NOTPARALLEL:
.PHONY:				debug all clean fclean re tests_run
