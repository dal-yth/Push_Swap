NAME1 = push_swap

NAME2 = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

DIR_S = srcs

DIR_O = obj

SOURCES = add_color.c eval_input.c insert_counts.c insert_rot.c \
		insert_utils.c insertsort.c list_ops.c make_arr.c medians.c \
		ops1.c ops2.c ops3.c opti_output.c push_count.c quicksort.c \
		solve3.c utils1.c utils2.c visu_utils.c visu.c

PW_SRC = push_swap.c

CH_SRC = checker.c

LIBFT = libft/libft.a

INC = includes/

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJ = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

PW_OBJ = $(addprefix $(DIR_O)/,$(PW_SRC:.c=.o))

CH_OBJ = $(addprefix $(DIR_O)/,$(CH_SRC:.c=.o))

all: $(NAME1)

# @ supresses 'echo' of the command
$(NAME1): $(OBJ) $(PW_OBJ) $(CH_OBJ)
	@echo "Compiling library..."
	@cd libft && make
	@echo "Creating executables..."
	@$(CC) -o $(NAME1) $(FLAGS) $(PW_OBJ) $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME2) $(FLAGS) $(CH_OBJ) $(OBJ) $(LIBFT)
	@echo "$(NAME1) and $(NAME2) created."

# $@ is the name of file being generated
# $@ evaluates to $(DIR_O)/%.o
# $< first prerequisite
# $< evaluates to $(DIR_S)/%.c $(PF_DIR_S)/%.c
$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

$(DIR_O)/%.o: %.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	@echo "Removing libft objects..."
	@cd libft && make clean
	@echo "Removing project objects..."
	@rm -f $(OBJ)
	@rm -f $(PW_OBJ)
	@rm -f $(CH_OBJ)
	@echo "Removing object directory..."
	@rm -rf $(DIR_O)

fclean: clean
	@echo "Removing libft.a..."
	@cd libft && make fclean
	@echo "Removing executables..."
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
