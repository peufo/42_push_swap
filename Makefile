NAME		=	push_swap
DIR_SRC		=	./
DIR_BUILD	=	build
FT_PRINTF	=	./lib/ft_printf
FLAGS		=	-Wall -Wextra -Werror

SOURCES		=	main.c 
FUNCTIONS	=	$(subst .c,,$(notdir $(SOURCES)))
OBJECTS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(FT_PRINTF)
	@cc $(OBJECTS) $(FLAGS) -L $(FT_PRINTF) -lftprintf -o $(NAME)

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) -I $(FT_PRINTF) -c $^ -o $@

$(DIR_BUILD):
	@mkdir $(DIR_BUILD)

$(LIBS):
	@make -C $@

clean:
	make clean -C $(FT_PRINTF)
	rm -rf $(DIR_BUILD)

fclean: clean
	make fclean -C $(FT_PRINTF)
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all
	make re -C $(FT_PRINTF)

