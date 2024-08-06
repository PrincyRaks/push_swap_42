/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:33:31 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/01 14:55:33 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_min_cost_a(t_stack *first_a, t_stack *first_b)
{
	int		len_a;
	int		len_b;
	int		min_cost;
	t_stack	*node_a;

	len_a = count_node(first_a);
	len_b = count_node(first_b);
	node_a = first_a;
	min_cost = cost_node_a(first_a, first_b, len_a, len_b);
	while (first_a)
	{
		if (min_cost > cost_node_a(first_a, first_b, len_a, len_b))
		{
			min_cost = cost_node_a(first_a, first_b, len_a, len_b);
			node_a = first_a;
		}
		first_a = first_a->next;
	}
	return (node_a);
}

static t_stack	*get_min_cost_b(t_stack *first_a, t_stack *first_b)
{
	int		len_a;
	int		len_b;
	int		min_cost;
	t_stack	*node_b;

	len_a = count_node(first_a);
	len_b = count_node(first_b);
	node_b = first_b;
	min_cost = cost_node_b(first_b, first_a, len_b, len_a);
	while (first_b)
	{
		if (min_cost > cost_node_b(first_b, first_a, len_b, len_a))
		{
			min_cost = cost_node_b(first_b, first_a, len_b, len_a);
			node_b = first_b;
		}
		first_b = first_b->next;
	}
	return (node_b);
}

static void	push_to_b(t_stack *to_range, t_stack **stack_a, t_stack **stack_b)
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

static void	push_to_a(t_stack *to_range, t_stack **stack_b, t_stack **stack_a)
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

	while (count_node(*a) > 3 && !is_asc(*a) && !sortable(*a))
	{
		min_cost = get_min_cost_a(*a, *b);
		push_to_b(min_cost, a, b);
	}
	if (sortable(*a))
		re_order_a(a, count_node(*a));
	if (!is_asc(*a) && count_node(*a) == 3)
		sort_three(a);
	if (is_asc(*a))
	{
		while (count_node(*b) > 0)
		{
			min_cost = get_min_cost_b(*a, *b);
			push_to_a(min_cost, b, a);
		}
		re_order_a(a, count_node(*a));
	}
}
