##
## EPITECH PROJECT, 2019
## CPE_corewar_2019
## File description:
## Compiles the corewar and asm programs
##

ASM_PATH		=	asm

VM_PATH			= 	corewar

all:
				$(MAKE) -C $(ASM_PATH)
				$(MAKE) -C $(VM_PATH)

tests_run:
				$(MAKE) $@ -C $(ASM_PATH)
				$(MAKE) $@ -C $(VM_PATH)

clean:
				$(MAKE) clean -C $(ASM_PATH)
				$(MAKE) clean -C $(VM_PATH)

fclean:
				$(MAKE) fclean -C $(ASM_PATH)
				$(MAKE) fclean -C $(VM_PATH)

re:
				$(MAKE) re -C $(ASM_PATH)
				$(MAKE) re -C $(VM_PATH)

.PHONY: 		all clean fclean re