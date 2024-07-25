/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:55:40 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 14:25:25 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_move(void (*move)(t_stack **), t_stack **data, char *msg, int n)
{
	while (n-- > 0)
	{
		move(data);
		ft_putstr_fd(msg);
	}
}

void	exec_both(void (*move)(t_stack **), t_stack **a, t_stack **b, int n)
{
	while (n-- > 0)
	{
		move(a);
		move(b);
		if (move == rotate)
			ft_putstr_fd("rr");
		else if (move == r_rotate)
			ft_putstr_fd("rrr");
	}
}

void	move_both(t_stack *to_range, t_stack **stack_a, t_stack **stack_b)
{
	int	target_a;
	int	move;
	int	len_a;
	int	len_b;

	len_a = count_node(*stack_a);
	len_b = count_node(*stack_b);
	target_a = get_target_index(to_range, *stack_b);
	if (to_range->index <= (len_a / 2) && target_a <= (len_b / 2))
	{
		if (to_range->index >= target_a)
			move = target_a;
		else
			move = to_range->index;
		exec_both(rotate, stack_a, stack_b, move);
	}
	else if (to_range->index >= (len_a / 2) && target_a >= (len_b / 2))
	{
		if ((len_a - to_range->index) <= (len_b - target_a))
			move = len_a - to_range->index;
		else
			move = len_b - target_a;
		exec_both(r_rotate, stack_a, stack_b, move);
	}
}

void	handle_stack_a_moves(t_stack *to_range, t_stack **stack_a, int len_a)
{
	int	median_a;
	int	index_a;

	median_a = median(len_a);
	index_a = to_range->index;
	if (index_a <= median_a)
		exec_move(rotate, stack_a, "ra", index_a);
	else
		exec_move(r_rotate, stack_a, "rra", len_a - index_a);
}

void	handle_stack_b_moves(t_stack *to_range, t_stack **stack_b, int len_b)
{
	int	median_b;
	int	target_a;

	median_b = median(len_b);
	target_a = get_target_index(to_range, *stack_b);
	if (target_a <= median_b)
		exec_move(rotate, stack_b, "rb", target_a);
	else
		exec_move(r_rotate, stack_b, "rrb", len_b - target_a);
}
