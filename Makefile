NO_COLOR= \x1b[0m
B_GRY	= \x1b[30;01m
B_RED	= \x1b[31;01m
B_GRN	= \x1b[32;01m
B_YEL	= \x1b[33;01m
B_BLU	= \x1b[34;01m
B_PURP	= \x1b[35;01m
B_TURQ	= \x1b[36;01m
B_WHT	= \x1b[37;01m
GRY		= \x1b[30m
RED		= \x1b[31m
GRN		= \x1b[32m
YEL		= \x1b[33m
BLU		= \x1b[34m
PURP	= \x1b[35m
TURQ	= \x1b[36m
WHT		= \x1b[37m
CC		= gcc
CFLAGS	= -Wall -Wextra
PS_SRC	= main.c init.c exit.c algos.c printstack.c move.c
C_SRC	= main.c init.c exit.c instructions.c sort.c algos.c
PS_ODIR	:= sources/ps_obj
C_ODIR	:= sources/c_obj
PS_OBJ	= $(PS_ODIR)/main.o $(PS_ODIR)/init.o $(PS_ODIR)/exit.o \
		  $(PS_ODIR)/algos.o $(PS_ODIR)/printstack.o $(PS_ODIR)/move.o
C_OBJ	= $(C_ODIR)/main.o $(C_ODIR)/init.o $(C_ODIR)/exit.o \
		  $(C_ODIR)/instructions.o $(C_ODIR)/sort.o $(C_ODIR)/algos.o
INC		= sources/includes
LIB		= sources/libft.a
EX1		= push_swap
EX2		= checker


all: $(LIB) $(EX1) $(EX2)

$(EX1): $(PS_OBJ)
	$(CC) $(CFLAGS) -I $(INC) -o $(EX1) $(PS_OBJ) -L./sources/ -lft

$(EX2): $(C_OBJ)
	$(CC) $(CFLAGS) -I $(INC) -o $(EX2) $(C_OBJ) -L./sources/ -lft

$(PS_ODIR)/%.o:sources/ps_src/%.c | $(PS_ODIR)
	$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

$(C_ODIR)/%.o:sources/c_src/%.c | $(C_ODIR)
	$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

$(PS_ODIR):
	@mkdir $(PS_ODIR)

$(C_ODIR):
	@mkdir $(C_ODIR)

$(LIB):
	@make -C sources/libft/

clean:
	@rm -rf $(PS_ODIR)
	@rm -rf $(C_ODIR)
	@make -C sources/libft/ clean

fclean: clean
	@rm -f $(EX1) $(EX2)
	@make -C sources/libft/ fclean

re: fclean all

.PHONY: clean fclean all re
