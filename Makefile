CFLAGS= -Wall -Werror -Wextra
SRCS= check_input.c check_stack.c cost.c cost_utils.c exec_move_1.c \
	exec_move_2.c init_data.c main.c move_utils.c print_error.c \
	push_swap.c range_algo.c sort_3.c stack_utils_1.c stack_utils_2.c 

LIBFT_SRCS= ./libft/ft_atoi.c \
	./libft/ft_bzero.c \
	./libft/ft_calloc.c \
	./libft/ft_isalpha.c \
	./libft/ft_isdigit.c \
	./libft/ft_putstr_fd.c \
	./libft/ft_split.c \
	./libft/ft_strchr.c \
	./libft/ft_strlen.c \
	./libft/ft_isspace.c

OBJS= $(SRCS:.c=.o)
LIBFT_OBJS= $(LIBFT_SRCS:.c=.o)
NAME= push_swap

test1= 99 -2147483648 23 545
test2= 1 2 3 5 67b778 947
test3= " 49 128     50 38   49"
test4= 54867543867438 3

all: $(NAME)

$(LIBFT_OBJS):%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT_OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME) $(test4)

.PHONY: clean fclean re bonus all