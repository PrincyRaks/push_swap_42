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

// void	insert_target_index(t_stack **a, t_stack **b)
// {
// 	t_stack	*node_a;

// 	if (!a || !b)
// 		return ;
// 	node_a = *a;
// 	while (node_a)
// 	{
// 		node_a->target_index = get_target_index(node_a, *b);
// 		node_a = node_a->next;
// 	}
// }

t_stack	*get_min_cost(t_stack *first_a, t_stack *first_b)
{
	int		len_a;
	int		len_b;
	int		min_cost;
	t_stack	*to_range;
	t_stack	*a;

	len_a = count_node(first_a);
	len_b = count_node(first_b);
	to_range = first_a;
	a = first_a;
	min_cost = cost_node(a, first_b, len_a, len_b);
	while (a)
	{
		if (min_cost > cost_node(a, first_b, len_a, len_b))
		{
			min_cost = cost_node(a, first_b, len_a, len_b);
			to_range = a;
		}
		a = a->next;
	}
	return (to_range);
}

void	push_to_b(t_stack *to_range, t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	len_b;

	len_a = count_node(*stack_a);
	len_b = count_node(*stack_b);
	move_both(to_range, stack_a, stack_b);
	handle_stack_a_moves(to_range, stack_a, len_a);
	handle_stack_b_moves(to_range, stack_b, len_b);
	push(stack_a, stack_b);
	ft_putstr_fd("pb");
}

void	range_algo(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;

	while (!sortable(*a) && (count_node(*a) > 3 && !is_asc(*a)))
	{
		min_cost = get_min_cost(*a, *b);
		push_to_b(min_cost, a, b);
	}
	// sort stack a: tant que a est asc : verifier si sortable
	// push_back_a : target b -> max value
}