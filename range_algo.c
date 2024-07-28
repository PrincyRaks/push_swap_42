/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:36 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/26 15:54:54 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min_cost_a(t_stack *first_a, t_stack *first_b)
{
	int		len_a;
	int		len_b;
	int		min_cost;
	t_stack	*node_a;
	t_stack	*a;

	len_a = count_node(first_a);
	len_b = count_node(first_b);
	node_a = first_a;
	a = first_a;
	min_cost = cost_node_a(a, first_b, len_a, len_b);
	while (a)
	{
		if (min_cost > cost_node_a(a, first_b, len_a, len_b))
		{
			min_cost = cost_node_a(a, first_b, len_a, len_b);
			node_a = a;
		}
		a = a->next;
	}
	return (node_a);
}

t_stack	*get_min_cost_b(t_stack *first_a, t_stack *first_b)
{
	int		len_a;
	int		len_b;
	int		min_cost;
	t_stack	*node_b;
	t_stack	*b;

	len_a = count_node(first_a);
	len_b = count_node(first_b);
	node_b = first_b;
	b = first_b;
	min_cost = cost_node_b(b, first_a, len_b, len_a);
	while (b)
	{
		if (min_cost > cost_node_b(b, first_a, len_b, len_a))
		{
			min_cost = cost_node_b(b, first_a, len_b, len_a);
			node_b = b;
		}
		b = b->next;
	}
	return (node_b);
}

void	push_to_b(t_stack *to_range, t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	len_b;

	len_a = count_node(*stack_a);
	len_b = count_node(*stack_b);
	move_both(to_range, stack_a, stack_b, 0);
	handle_stack_a_moves(to_range, stack_a, len_a);
	handle_stack_b_moves(to_range, stack_b, len_b);
	push(stack_a, stack_b);
	ft_putstr_fd("pb");
}

void	push_to_a(t_stack *to_range,t_stack **stack_b, t_stack **stack_a)
{
	int	len_a;
	int	len_b;

	len_a = count_node(*stack_a);
	len_b = count_node(*stack_b);
	move_both(to_range, stack_b, stack_a, 1);
	handle_stack_b_back(to_range, stack_b, len_b);
	handle_stack_a_back(to_range, stack_a, len_a);
	push(stack_b, stack_a);
	ft_putstr_fd("pa");
}

void	range_algo(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;
	int		move;

	while (!sortable(*a) && (count_node(*a) > 3 && !is_asc(*a)))
	{
		min_cost = get_min_cost_a(*a, *b);
		push_to_b(min_cost, a, b);
	}
	move = sortable(*a);
	if (move > 0)
		exec_move(rotate, a, "ra", move);
	if (!is_asc(*a) && count_node(*a) == 3)
		sort_three(a);
	if (is_asc(*a))
	{
		while (count_node(*b) > 1)
		{
			min_cost = get_min_cost_b(*a, *b);
			push_to_a(min_cost, b, a);
		}
	}
}