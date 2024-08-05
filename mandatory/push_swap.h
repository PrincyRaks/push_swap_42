/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:31:13 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/01 15:08:22 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;
void				print_error(void);
int					strlen_tab(char **str);
char				*ft_strjoin_data(char *s1, char *s2);
int					not_dup(long *number, unsigned int size);
int					check_number(char *s);
long				*convert_int(char **str, int size);
t_stack				*init_data(char **argv);
t_stack				*create_node(int number, int index);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
int					count_node(t_stack *lst);
void				add_front(t_stack **lst, t_stack *node);
void				load_stack(t_stack **stack);
void				swap(t_stack **first);
void				rotate(t_stack **first);
void				r_rotate(t_stack **first);
void				push(t_stack **send, t_stack **receive);
int					is_asc(t_stack *first);
int					is_desc(t_stack *first);
int					is_max(t_stack *node, t_stack *first);
int					is_min(t_stack *node, t_stack *first);
t_stack				*get_value_max(t_stack *first);
t_stack				*get_value_min(t_stack *first);
int					target_min_index(t_stack *node_a, t_stack *first_b);
int					target_max_index(t_stack *node_b, t_stack *first_a);
int					cost_node_a(t_stack *node_a, t_stack *first_b, int len_a,
						int len_b);
int					cost_node_b(t_stack *node_b, t_stack *first_a, int len_b,
						int len_a);
void				exec_move(void (*move)(t_stack **), t_stack **data,
						char *msg, int n);
void				move_both(t_stack *to_range, t_stack **s_1, t_stack **s_2,
						int back);
void				handle_stack_a_moves(t_stack *to_range, t_stack **stack_a,
						int len_a);
void				handle_stack_b_moves(t_stack *to_range, t_stack **stack_b,
						int len_b);
void				handle_stack_a_back(t_stack *to_range, t_stack **stack_a,
						int len_a);
void				handle_stack_b_back(t_stack *to_range, t_stack **stack_b,
						int len_b);
void				sort_three(t_stack **a);
int					sortable(t_stack *a);
void				push_swap(t_stack **a, t_stack **b);
void				range_algo(t_stack **a, t_stack **b);
void				free_list(t_stack **node);
void				re_order_a(t_stack **a, int len_a);
void				pb(t_stack **send, t_stack **receive);

#endif