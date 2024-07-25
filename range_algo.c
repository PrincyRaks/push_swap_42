/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:36 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 14:25:49 by rrakotos         ###   ########.fr       */
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

void	get_min_cost(t_stack **first_a, t_stack **first_b)
{
	int		len_a;
	int		len_b;
	int		min_cost;
	t_stack	*to_range;
	t_stack	*a;

	len_a = count_node(*first_a);
	len_b = count_node(*first_b);
	to_range = *first_a;
	a = *first_a;
	min_cost = cost_node(a, *first_b, len_a, len_b);
	while (a)
	{
		if (min_cost > cost_node(a, *first_b, len_a, len_b))
		{
			min_cost = cost_node(a, *first_b, len_a, len_b);
			to_range = a;
		}
		a = a->next;
	}
	if (to_range)
		sort_move_1(to_range, first_a, first_b);
	// return (to_range);
}

void	sort_move_1(t_stack *to_range, t_stack **stack_a, t_stack **stack_b)
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

// void	sort_move_1(t_stack *to_range, t_stack **stack_a, t_stack **stack_b,
// int len_a, int len_b)
// {
// 	int	median_a;
// 	int	median_b;
// 	int	index_a;
// 	int	target_a;
// 	int	move;

// 	median_a = median(len_a);
// 	median_b = median(len_b);
// 	index_a = to_range->index;
// 	target_a = get_target_index(to_range, *stack_b);
// 	// r
// 	if (index_a <= median_a && target_a <= median_b)
// 	{
// 		if (index_a >= target_a)
// 			move = target_a;
// 		else
// 			move = index_a;
// 		exec_both(rotate, stack_a, stack_b, move);
// 		target_a = get_target_index(to_range, *stack_b);
// 		index_a = to_range->index;
// 	}
// 	// rr
// 	else if (index_a > median_a && target_a > median_b)
// 	{
// 		if ((len_a - index_a) <= (len_b - target_a))
// 			move = len_a - index_a;
// 		else
// 			move = len_b - target_a;
// 		exec_both(r_rotate, stack_a, stack_b, move);
// 		target_a = get_target_index(to_range, *stack_b);
// 		index_a = to_range->index;
// 	}
// 	// pile A
// 	if (index_a <= median_a)
// 		exec_move(rotate, stack_a, "ra", index_a);
// 	else if (index_a > median_a)
// 		exec_move(r_rotate, stack_a, "rra", (len_a - index_a));
// 	// PILE B
// 	if (target_a <= median_b)
// 		exec_move(rotate, stack_b, "rb", target_a);
// 	else if (target_a > median_b)
// 		exec_move(r_rotate, stack_b, "rrb", (len_b - target_a));
// 	push(stack_a, stack_b);
// 	ft_putstr_fd("pb", FD);
// }