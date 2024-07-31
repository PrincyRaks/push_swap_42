/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:19:12 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/31 00:19:12 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free_list(t_stack **node)
{
	free_list(node);
	print_error();
}

void	free_list(t_stack **node)
{
	t_stack *current;
	t_stack *next_node;

	current = *node;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

int	sortable(t_stack *a)
{
	t_stack *node_min;
	t_stack *node_top;

	node_min = get_value_min(a);
	node_top = a;
	if (!is_asc(node_min))
		return (0);
	if (node_top->value < ft_lstlast(a)->value)
		return (0);
	while (node_top->next && (node_top != node_min))
	{
		if (node_top->next == node_min
			&& node_top->value > node_top->next->value)
			return (0);
		node_top = node_top->next;
	}
	return (1);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int len_a;
	int move;

	if (!b)
		free_list(a);
	len_a = count_node(*a);
	move = sortable(*a);
	if (len_a == 2 && !is_asc(*a))
		exec_move(swap, a, "sa", 1);
	else if (len_a == 3 && !is_asc(*a))
		sort_three(a);
	else if (len_a > 3 && move)
		re_order_a(a, len_a);
	else if (len_a > 3 && !move && !is_asc(*a))
	{
		move = 2;
		while (move-- > 0)
		{
			push(a, b);
			ft_putstr_fd("pb");
		}
		range_algo(a, b);
	}
}
