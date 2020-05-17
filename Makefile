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

debug:
				$(MAKE) $@ -C $(ASM_PATH)
				$(MAKE) $@ -C $(VM_PATH)
tests_run:
				$(MAKE) $@ -C $(ASM_PATH)
				$(MAKE) $@ -C $(VM_PATH)

clean:
				$(MAKE) $@ -C $(ASM_PATH)
				$(MAKE) $@ -C $(VM_PATH)

fclean:
				$(MAKE) $@ -C $(ASM_PATH)
				$(MAKE) $@ -C $(VM_PATH)

re:
				$(MAKE) $@ -C $(ASM_PATH)
				$(MAKE) $@ -C $(VM_PATH)

.PHONY: 		all clean fclean re