NAME = a.out
OFILES = $(SRCS:.c=.o)
INCLUDES = includes
LIB = libft.a
SRCS =	main.c \
		command_input.c \
		stacks.c \
		stack_functions.c

all: $(NAME)

$(NAME):
	make -C libft	
	cp libft/$(LIB) .
	gcc $(SRCS) $(LIB) -o $(NAME) -I $(INCLUDES) -I libft 
clean:
	make clean -f libft/Makefile
	rm -f $(OFILES)

fclean: clean
	make fclean -f libft/Makefile
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

