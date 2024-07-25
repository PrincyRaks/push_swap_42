/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:03 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 10:51:03 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int value;
	int index;
	// int target_index;
	struct s_stack *top;
	struct s_stack *bottom;
	struct s_stack *next;
} t_stack;
void	print_error(void);
long	*check_dup(char **data, int size);
int	strlen_tab(char **str);
char	*ft_strjoin_data(char *s1, char *s2);
long	*convert_int(char **str, int size);
int	not_dup(long *number, int size);
int	check_number(char *s);
t_stack	*init_data(char **argv);
int	is_empty(char *str);
char	*join_argv(char **argv);

t_stack	*init_stack(long *tab_num, int size);
t_stack	*create_node(int number, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int	count_node(t_stack *lst);
void	add_top_bottom(t_stack **lst, t_stack *tail);
void	add_front(t_stack **lst, t_stack *node);
void	load_stack(t_stack **stack);

void	swap(t_stack **first);
void	rotate(t_stack **first);
void	r_rotate(t_stack **first);
void	push(t_stack **send, t_stack **receive);

int	is_asc(t_stack *first);
int	is_desc(t_stack *first);
int	is_max(t_stack *node, t_stack *first);
int	is_min(t_stack *node, t_stack *first);
t_stack	*get_value_max(t_stack *first);

int	get_target_index(t_stack *node_a, t_stack *first_b);
// void	insert_target_index(t_stack **a, t_stack **b);
int	median(int length);
int	cost_both(int index, int target_i, int len_a, int len_b);
int	cost_individual(int index, int len);
int	cost_node(t_stack *node_a, t_stack *first_b, int len_a, int len_b);
// t_stack	*get_min_cost(t_stack *first_a, t_stack *first_b);
void	get_min_cost(t_stack **first_a, t_stack **first_b);
// void	sort_move_1(t_stack *to_range, t_stack **stack_b, int len_a,int len_b);

void	exec_move(void (*move)(t_stack **), t_stack **data, char *msg, int n);
void	exec_both(void (*move)(t_stack **), t_stack **a, t_stack **b, int n);
void	sort_move_1(t_stack *to_range, t_stack **stack_a, t_stack **stack_b);

void	sort_three(t_stack **a);

#endif