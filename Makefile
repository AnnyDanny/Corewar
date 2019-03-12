# Name1 of the program
NAME1	:= asm
NAME2	:= corewar

# Directories
OBJ_DIR		:=	./obj/
ASM_SRC_DIR	:=	./assembler/
VM_SRC_DIR	:=	./vm/
INC_DIR		:=	./inc/

LIBFT_DIR :=	./libft/
LIBFT_INC :=	./libft/inc/
LIBFT := 		$(LIBFT_DIR)libft.a

# Source and object files
ASM_SRC	:= asm.c asm_op.c main.c read_data.c add_data_to_list.c \
		trim_remaining_list_strings.c validate_header.c validate_instructions.c \
		handle_label.c handle_ops.c handle_op_params.c fill_label_references.c \
		free_t_asm.c write_to_output_file.c validate_header_utils.c \
		add_label_reference.c handle_op_params_utils.c error_handling.c \

VM_SRC	:= corewar.c argreader.c binfuncs.c memfuncs.c machine.c cmndfuncs.c \
		procfuncs.c add_sub.c get_args.c live_zjmp_fork_lfork_aff.c \
		and_or_xor.c ld_ldi_lld_lldi.c st_sti.c init_window.c draw_skelet.c \
		draw_all.c draw_helper.c draw_colors.c add_to_get_args.c \
		add_to_live.c add_to_proc.c kill_proc.c add_to_st_sti.c utils.c \
		add_to_ld_ldi_lld_lldi.c usage.c 

ASM_OBJ		:= $(addprefix $(OBJ_DIR), $(ASM_SRC:.c=.o))
VM_OBJ		:= $(addprefix $(OBJ_DIR), $(VM_SRC:.c=.o))

# Compiler and flags
CC		:= clang -g

FLAGS	:= -Wall -Wextra -Werror

# Compile and link the program
all: lib obj_dir $(NAME1) $(NAME2)

# Link object files into the executable
$(NAME1): $(ASM_OBJ)
	$(CC) $(ASM_OBJ) -o $(NAME1) $(LIBFT) -I $(INC_DIR) -I $(LIBFT_INC)

$(NAME2): $(VM_OBJ)
	$(CC) $(VM_OBJ) -o $(NAME2) $(LIBFT) -I $(INC_DIR) -I $(LIBFT_INC) -lncurses

# Compile object files from source files
$(OBJ_DIR)%.o: $(ASM_SRC_DIR)%.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR) -I $(LIBFT_INC)

$(OBJ_DIR)%.o: $(VM_SRC_DIR)%.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR) -I $(LIBFT_INC)

# Compile my library
lib:
	@make -C $(LIBFT_DIR)

# Create a directory for object files
obj_dir:
	@mkdir -p $(OBJ_DIR)

# Delete object files
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Delete all files created with the Makefile
fclean:
	rm -f $(NAME1) $(NAME2)
	rm -rf $(OBJ_DIR)
	rm -rf test_warriors/*.cor
	make -C $(LIBFT_DIR) fclean

# Re-make all files
re: fclean all

# GNU will run even if files have name1s as instructions
.PHONY: all clean fclean re
