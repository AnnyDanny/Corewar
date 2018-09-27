# CC = clang
# NAME = corewar
# FLAGS = += -g -I $(path) lib -I $(path) .
# SRC = add_sub.c and_or_xor.c argreader.c binfuncs.c cmndfuncs.c corewar.c get_args.c ld_ldi_lld_lldi.c \
# live_zjmp_fork_lfork_aff.c machine.c memfuncs.c procfuncs.c st_sti.c
# OBJ = $(SRC:.c=.o)

# all: $(NAME)
	
# $(NAME):$(OBJ)
# 	$(MAKE) -C .lib
# 	$(CC) $(FLAGS) $(OBJ)  -L /lib -lft -o $@

# $(OBJ):
# $(CC) $(FLAGS) -c $(SRC)

# clean:
#  			rm -f *.o

# fclean: clean
#  			rm -f $(NAME)

# re: fclean all


CC = clang
FLAGS += -g -I $(path) lib -I $(path) .
NAME = corewar
FILES = add_sub and_or_xor argreader binfuncs cmndfuncs corewar get_args ld_ldi_lld_lldi \
live_zjmp_fork_lfork_aff machine memfuncs procfuncs st_sti
SRC = $(addsuffix .c, $(FILES))

OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib
	$(CC) $(FLAGS) $(OBJ)  -L lib -lft -o $@

$(OBJ):
	$(CC) $(FLAGS) -c $(SRC)

clean:
			rm -f *.o

fclean: clean
			rm -f $(NAME)

re: fclean all