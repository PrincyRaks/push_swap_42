CFLAGS= -Wall -Werror -Wextra
SRCS= check_dup.c \
	stack_utils.c \
	move_utils.h \
	main.c 

LIBFT_SRCS= ./libft/ft_atoi.c \
	./libft/ft_bzero.c \
	./libft/ft_calloc.c \
	./libft/ft_isalpha.c \
	./libft/ft_isdigit.c \
	./libft/ft_putstr_fd.c \
	./libft/ft_split.c \
	./libft/ft_strchr.c \
	./libft/ft_strlen.c \
	./libft/ft_lstadd_back_bonus.c \
	./libft/ft_lstlast_bonus.c \
	./libft/ft_isspace.c

OBJS= $(SRCS:.c=.o)
LIBFT_OBJS= $(LIBFT_SRCS:.c=.o)
NAME= push_swap.a

all: $(NAME)

$(OBJS):%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(LIBFT_OBJS):%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(OBJS) $(UTILS_OBJS)

clean: 
	rm -f $(OBJS) $(UTILS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re bonus all

