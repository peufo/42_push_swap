NAME		=	push_swap
DIR_SRC		=	./src
DIR_BUILD	=	./build
FT_PRINTF	=	./lib/ft_printf
LIBFT		=	./lib/libft
FLAGS		=	-Wall -Wextra -Werror

SOURCES		=	array/delta.c array/parse.c array/print.c array/push.c array/rotate.c array/rotate_r.c array/swap.c main.c resolve.c 
FUNCTIONS	=	$(subst .c,,$(SOURCES))
OBJECTS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(FT_PRINTF)
	@make -C $(LIBFT)
	@cc $(OBJECTS) $(FLAGS) -L $(FT_PRINTF) -lftprintf -L $(LIBFT) -lft -o $(NAME)

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) -I $(FT_PRINTF) -I $(LIBFT) -c $^ -o $@

$(DIR_BUILD):
	@mkdir -p $(DIR_BUILD)/array

$(LIBS):
	@make -C $@

clean:
	make clean -C $(FT_PRINTF)
	make clean -C $(LIBFT)
	rm -rf $(DIR_BUILD)

fclean: clean
	make fclean -C $(FT_PRINTF)
	make fclean -C $(LIBFT)
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all
	make re -C $(FT_PRINTF)
	make re -C $(LIBFT)
