MAIN_SRC= ./mandatory/main.c
MAIN_BONUS= ./bonus/main.c
CFLAGS= -Wall -Werror -Wextra
SRCS=	./mandatory/check_input.c \
		./mandatory/check_stack.c \
		./mandatory/cost.c \
		./mandatory/cost_utils.c \
		./mandatory/exec_move_1.c \
		./mandatory/exec_move_2.c \
		./mandatory/init_data.c \
		./mandatory/move_utils.c \
		./mandatory/print_error.c \
		./mandatory/push_swap.c \
		./mandatory/range_algo.c \
		./mandatory/sort_3.c \
		./mandatory/stack_utils_1.c \
		./mandatory/stack_utils_2.c

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
MAIN_OBJS= $(MAIN_SRC:.c=.o)
MAIN_BONUS_OBJS= $(MAIN_BONUS:.c=.o)
NAME= push_swap
NAME_BONUS= checker

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT_OBJS):%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(OBJS):%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(BONUS_OBJS):%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(MAIN_BONUS_OBJS):%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(MAIN_OBJS):%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS) $(MAIN_OBJS)
	cc $(CFLAGS) $(MAIN_OBJS) $(OBJS) $(LIBFT_OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS) $(BONUS_OBJS) $(LIBFT_OBJS) $(MAIN_BONUS_OBJS)
	cc $(CFLAGS) $(MAIN_BONUS_OBJS) $(BONUS_OBJS) $(OBJS) $(LIBFT_OBJS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(LIBFT_OBJS) $(BONUS_OBJS) $(MAIN_OBJS) $(MAIN_BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean $(NAME)

.PHONY: clean fclean re bonus all