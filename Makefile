NAME = a.out
OFILES = $(SRCS:.c=.o)
INCLUDES = includes
LIB = libft.a
SRCS =	srcs/checker/main.c \
		srcs/checker/command_input.c \
		srcs/checker/stacks.c \
		srcs/checker/stack_functions.c \
		srcs/error_mgr.c \
		srcs/read_arguments.c

all: $(NAME)

$(NAME):
	@make -C libft	
	@cp libft/$(LIB) .
	@gcc $(SRCS) $(LIB) -o $(NAME) -I $(INCLUDES) -I libft 
	@echo $(NAME) created

clean:
	make clean -f libft/Makefile
	rm -f $(OFILES)

fclean: clean
	make fclean -f libft/Makefile
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

