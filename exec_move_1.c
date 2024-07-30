/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:07:44 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/28 23:07:44 by rrakotos         ###   ########.fr       */
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

void	move_both(t_stack *to_range, t_stack **s_1, t_stack **s_2, int back)
{
	int	target_i;
	int	move;
	int	len_1;
	int	len_2;

	len_1 = count_node(*s_1);
	len_2 = count_node(*s_2);
	target_i = target_min_index(to_range, *s_2);
	if (back)
		target_i = target_max_index(to_range, *s_2);
	if (to_range->index <= (len_1 / 2) && target_i <= (len_2 / 2))
	{
		move = to_range->index;
		if (to_range->index >= target_i)
			move = target_i;
		exec_both(rotate, s_1, s_2, move);
	}
	else if (to_range->index >= (len_1 / 2) && target_i >= (len_2 / 2))
	{
		move = len_2 - target_i;
		if ((len_1 - to_range->index) <= (len_2 - target_i))
			move = len_1 - to_range->index;
		exec_both(r_rotate, s_1, s_2, move);
	}
	// load_stack(s_1);
	// load_stack(s_2);
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
	target_a = target_min_index(to_range, *stack_b);
	if (target_a <= median_b)
		exec_move(rotate, stack_b, "rb", target_a);
	else
		exec_move(r_rotate, stack_b, "rrb", len_b - target_a);
}