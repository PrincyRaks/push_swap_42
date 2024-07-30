/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:06:20 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/30 23:46:09 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_stack_b_back(t_stack *to_range, t_stack **stack_b, int len_b)
{
	int	index_b;

	index_b = to_range->index;
	if (index_b <= (len_b / 2))
		exec_move(rotate, stack_b, "rb", index_b);
	else
		exec_move(r_rotate, stack_b, "rrb", len_b - index_b);
}

void	handle_stack_a_back(t_stack *to_range, t_stack **stack_a, int len_a)
{
	int	target_b;

	target_b = target_max_index(to_range, *stack_a);
	if (target_b <= (len_a / 2))
		exec_move(rotate, stack_a, "ra", target_b);
	else
		exec_move(r_rotate, stack_a, "rra", len_a - target_b);
}

void	re_order_a(t_stack **a, int len_a)
{
	t_stack *first;

	first = get_value_min(*a);
	if (first->index <= (len_a / 2))
	{
		while (!is_asc(*a))
			exec_move(rotate, a, "ra", 1);
	}
	else
	{
		while (!is_asc(*a))
			exec_move(r_rotate, a, "rra", 1);
	}
}