/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:06:20 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/28 23:14:16 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_stack_b_back(t_stack *to_range, t_stack **stack_b, int len_b)
{
	int	median_b;
	int	index_b;

	median_b = median(len_b);
	index_b = to_range->index;
	if (index_b <= median_b)
		exec_move(rotate, stack_b, "rb", index_b);
	else
		exec_move(r_rotate, stack_b, "rrb", len_b - index_b);
}

void	handle_stack_a_back(t_stack *to_range, t_stack **stack_a, int len_a)
{
	int	median_a;
	int	target_b;

	median_a = median(len_a);
	target_b = target_max_index(to_range, *stack_a);
	if (target_b <= median_a)
		exec_move(rotate, stack_a, "ra", target_b);
	else
		exec_move(r_rotate, stack_a, "rra", len_a - target_b);
}