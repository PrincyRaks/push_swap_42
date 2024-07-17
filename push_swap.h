/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/09 13:44:45 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/12 16:31:08 by rrakotos         ###   ########.fr       */
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

t_stack	*init_stack(long *tab_num, int size);
t_stack	*create_node(int number);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int	count_node(t_stack *lst);
void	add_top_bottom(t_stack **lst, t_stack *tail);
void	add_front(t_stack **lst, t_stack *node);
// void	load_stack(t_stack **stack);

void	swap(t_stack **first);
void	rotate(t_stack **first);
void	r_rotate(t_stack **first);
void	push(t_stack **send, t_stack **receive);

#endif