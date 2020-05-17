##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

MAIN				=	src/main.c										\

OP					=	src/op.c										\

SRC_COREWAR			=	src/corewar.c									\

SRC_DESTROY			=	src/destroy/destroy_setup.c						\
						src/destroy/destroy_vm.c						\

SRC_INIT			=	src/init/check_args.c							\
						src/init/get_champion.c							\
						src/init/get_champions.c						\
						src/init/get_names.c							\
						src/init/get_nbr_cycle_dump.c					\
						src/init/get_nbr_programs.c						\
						src/init/get_program_file.c						\
						src/init/get_program_opts.c						\
						src/init/get_program.c							\
						src/init/get_programs.c							\
						src/init/init_setup.c							\
						src/init/init_vm.c								\
						src/init/parse_program_file.c					\
						src/init/write_programs.c						\

SRC_INSTRUCTIONS 	=	src/instructions/instruction_add.c				\
						src/instructions/instruction_aff.c				\
						src/instructions/instruction_and.c				\
						src/instructions/instruction_fork.c				\
						src/instructions/instruction_ld.c				\
						src/instructions/instruction_ldi.c				\
						src/instructions/instruction_lfork.c			\
						src/instructions/instruction_live.c				\
						src/instructions/instruction_lld.c				\
						src/instructions/instruction_lldi.c				\
						src/instructions/instruction_or.c				\
						src/instructions/instruction_st.c				\
						src/instructions/instruction_sti.c				\
						src/instructions/instruction_sub.c				\
						src/instructions/instruction_xor.c				\
						src/instructions/instruction_zjmp.c				\

SRC_VM				=	src/vm/check_live_champions.c					\
						src/vm/copy_memory_n_bytes.c					\
						src/vm/dump_memory.c							\
						src/vm/dup_champion.c							\
						src/vm/execute_instruction.c					\
						src/vm/get_champion_color.c						\
						src/vm/get_instruction_params.c					\
						src/vm/get_ld_params_values.c					\
						src/vm/get_ops_params_values.c					\
						src/vm/get_winner.c								\
						src/vm/increment_pc.c							\
						src/vm/loop.c									\
						src/vm/update_memory_3d.c						\

SRC_GRAPHIC			=	src/graphic/draw/draw_map.c						\
						src/graphic/freer/free_map.c					\
						src/graphic/freer/free_win.c					\
						src/graphic/freer/freeer.c						\
						src/graphic/init/init_map_tiles.c				\
						src/graphic/init/init_map.c						\
						src/graphic/init/init_win.c						\
						src/graphic/update/camera/angle_rotation.c		\
						src/graphic/update/camera/center_cam.c			\
						src/graphic/update/camera/control_view.c		\
						src/graphic/update/camera/translations.c		\
						src/graphic/update/map/map_tiles.c				\
						src/graphic/update/win/mouse.c					\
						src/graphic/update/maths/project_iso_point.c	\
						src/graphic/update/win/win.c					\
						src/graphic/update/update.c						\


SRC_VECTOR_ENGINE	=	src/vector_engine/vec_angle.c					\
						src/vector_engine/vec_basic.c					\
						src/vector_engine/vec_cross.c					\
						src/vector_engine/vec_dot.c						\
						src/vector_engine/vec_lim.c						\
						src/vector_engine/vec_mag.c						\
						src/vector_engine/vec_norm.c					\
						src/vector_engine/vec_normal.c					\

SRC					=	$(OP) $(SRC_COREWAR) $(SRC_DESTROY) $(SRC_INIT) $(SRC_INSTRUCTIONS) $(SRC_VM) $(SRC_GRAPHIC) $(SRC_VECTOR_ENGINE)

OBJ					=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 				=	corewar

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/ -I./include/graphic

LDFLAGS				=	-L./lib/

override LDLIBS		+= 	-lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

LIB 				= lib/libmy.a

all:				$(NAME)

$(NAME):			$(LIB) $(OBJ)
					$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIB):
					$(MAKE) -C lib

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
					$(MAKE) -C lib clean
					$(RM) *.gcda
					$(RM) *.gcno
					$(RM) tests/*.gcda
					$(RM) tests/*.gcno
					$(RM) tests_run
					$(RM) debug

fclean:				clean
					$(RM) $(NAME)
					$(MAKE) -C lib fclean

re:			 		fclean all

.NOTPARALLEL:
.PHONY:				debug all clean fclean re tests_run
