MAIN_SRC= main.c
CFLAGS= -Wall -Werror -Wextra
SRCS= check_input.c check_stack.c cost.c cost_utils.c exec_move_1.c \
	exec_move_2.c init_data.c move_utils.c print_error.c \
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
	./libft/ft_isspace.c \
	./libft/ft_strncmp.c \
	./libft/ft_strlcpy.c

BONUS_SRCS= ./bonus/get_next_line.c \
			./bonus/get_next_line_utils.c \
			./bonus/check_move.c

OBJS= $(SRCS:.c=.o)
LIBFT_OBJS= $(LIBFT_SRCS:.c=.o)
BONUS_OBJS= $(BONUS_SRCS:.c=.o)
NAME= push_swap
NAME_BONUS= checker

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT_OBJS):%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(BONUS_OBJS):%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS)
	cc $(CFLAGS) $(MAIN_SRC) $(OBJS) $(LIBFT_OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS) $(BONUS_OBJS) $(LIBFT_OBJS)
	cc $(CFLAGS) -g ./bonus/$(MAIN_SRC) $(BONUS_OBJS) $(OBJS) $(LIBFT_OBJS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(LIBFT_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean $(NAME)

.PHONY: clean fclean re bonus all