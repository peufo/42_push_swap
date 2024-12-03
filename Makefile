NAME		=	push_swap
NAME_BONUS	=	checker
DIR_SRC		=	./src
DIR_BONUS	=	./bonus
DIR_BUILD	=	./build
FLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
INCLUDES	= 	-I $(DIR_SRC) -I $(DIR_SRC)/stack -I $(DIR_SRC)/libft

SOURCES		=	check_swap.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_putstr.c libft/ft_split.c libft/ft_strlen.c optimize.c push_swap.c resolve.c split_a.c split_b.c stack/moves.c stack/push.c stack/rotate.c stack/rotate_r.c stack/rotate_utils.c stack/stack.c stack/swap.c 
FUNCTIONS	=	$(subst .c,,$(SOURCES))
OBJECTS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))

SOURCES_BONUS	=	checker.c get_next_line.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_putstr.c libft/ft_split.c libft/ft_strlen.c stack/moves.c stack/push.c stack/rotate.c stack/rotate_r.c stack/rotate_utils.c stack/stack.c stack/swap.c 
FUNCTIONS_BONUS	=	$(subst .c,,$(SOURCES_BONUS))
OBJECTS_BONUS	=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS_BONUS)))

all: $(NAME)

$(NAME): $(OBJECTS)
	@cc $(OBJECTS) $(FLAGS) -o $(NAME)

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) $(INCLUDES) -c $^ -o $@

$(DIR_BUILD)/%.o: $(DIR_BONUS)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) $(INCLUDES) -c $^ -o $@

$(DIR_BUILD):
	@mkdir -p $(DIR_BUILD)/stack
	@mkdir -p $(DIR_BUILD)/libft

bonus: $(OBJECTS_BONUS)
	@cc $(OBJECTS_BONUS) $(FLAGS) $(INCLUDES) -o $(NAME_BONUS)

wasm:
	docker run --rm -v $(shell pwd):/src emscripten/emsdk emcc $(SOURCES) -o $(NAME).wasm

clean:
	rm -rf $(DIR_BUILD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME).wasm
	rm -f $(NAME_BONUS)

re: fclean all
