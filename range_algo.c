/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:36 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/23 16:48:25 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_min_max(t_stack *node_a, t_stack *b)
{
	if (node_a && b)
	{
		if (is_max(node_a, b) || is_min(node_a, b))
			return (1);
	}
	return (0);
}

unsigned int	get_target_index(t_stack *node_a, t_stack *first_b)
{
	t_stack	*min_index;
	t_stack	*stack_b;

	min_index = NULL;
	stack_b = first_b;
	while (first_b)
	{
		if ((node_a->value > first_b->value) && (min_index == NULL 
				|| first_b->value > min_index->value))
			min_index = first_b;
		first_b = first_b->next;
	}
	if (!min_index)
		return ((get_value_max(stack_b))->index);
	return (min_index->index);
}

void	insert_target_index(t_stack **a, t_stack **b)
{
	t_stack	*node_a;

	if (!a || !b)
		return ;
	node_a = *a;
	while (node_a)
	{
		node_a->target_index = get_target_index(node_a, *b);
		node_a = node_a->next;
	}
}

unsigned int	mediane(unsigned int length)
{
	unsigned int	result;

	result = length;
	if (result % 2 != 0)
		return ((result / 2) + 1);
	return (result / 2);
}

unsigned int	calculate_cost_node(t_stack *node_a, int length_a, int length_b)
{
	unsigned int	mediane_a;
	unsigned int	mediane_b;
	unsigned int	cost_a;
	unsigned int	cost_b;

	mediane_a = mediane(length_a);
	mediane_b = mediane(length_b);
	cost_a = 0;
	cost_b = 0;
	if (node_a->index <= mediane_a && node_a->target_index <= mediane_b)
	{
		if (node_a->index >= node_a->target_index)
			return (node_a->index + 1);
		return (node_a->target_index + 1);
	}
	else if (node_a->index > mediane_a && node_a->target_index > mediane_b)
	{
		if ((length_a - node_a->index) >= (length_b - node_a->target_index))
			return (length_a - node_a->index + 1);
		return (length_b - node_a->target_index + 1);
	}
	if (node_a->index < mediane_a)
		cost_a = node_a->index;
	if (node_a->index >= mediane_a)
		cost_a = length_a - node_a->index;
	if (node_a->target_index < mediane_b)
		cost_b = node_a->target_index;
	if (node_a->target_index >= mediane_b)
		cost_b = length_b - node_a->target_index;
	return (cost_a + cost_b + 1);
}

void	get_min_cost(t_stack **first_a, t_stack **first_b)
{
	unsigned int	len_a;
	unsigned int	len_b;
	unsigned int	min_cost;
	t_stack	*to_range;
	t_stack *a;
	
	len_a = count_node(*first_a);
	len_b = count_node(*first_b);
	to_range = *first_a;
	a = *first_a;
	min_cost = calculate_cost_node(a, len_a, len_b);
	while (a)
	{
		if (min_cost > calculate_cost_node(a, len_a, len_b))
		{
			min_cost = calculate_cost_node(a, len_a, len_b);
			to_range = a;
		}
		a = a->next;
	}
	if (to_range)
		launch_move_1(to_range,first_a, first_b, len_a, len_b);
	// return (to_range);
}

void	launch_move_1(t_stack *to_range, t_stack **stack_a, t_stack **stack_b, int length_a, int length_b)
{
	unsigned int	mediane_a;
	unsigned int	mediane_b;
	unsigned int	index_a;
	unsigned int	target_a;
	unsigned int	move;

	mediane_a = mediane(length_a);
	mediane_b = mediane(length_b);
	index_a = to_range->index;
	target_a = to_range->target_index;
	// r
	if (index_a <= mediane_a && target_a <= mediane_b)
	{
		if (index_a >= target_a)
			move = target_a;
		else
			move = index_a;
		while (move-- > 0)
		{
			printf("ATO 1\n");
			rotate(stack_a);
			rotate(stack_b);
			ft_putstr_fd("rr", FD);
		}
		if (index_a > target_a)
		{
			move = index_a - target_a;
			while (move-- > 0)
			{
				rotate(stack_a);
				ft_putstr_fd("ra", FD);
			}
		}
		else if (index_a < target_a)
		{
			move = target_a - index_a;
			while (move-- > 0)
			{
				rotate(stack_b);
				ft_putstr_fd("rb", FD);
			}
		}
	}
	// rr
	else if (index_a > mediane_a && target_a > mediane_b)
	{
		if ((length_a - index_a) <= (length_b - target_a))
			move = length_a - index_a;
		else
			move = length_b - target_a;
		while (move-- > 0)
		{
			r_rotate(stack_a);
			r_rotate(stack_b);
			ft_putstr_fd("rrr", FD);
		}
		if ((length_a - index_a) < (length_b - target_a))
		{
			move = (length_b - target_a) - (length_a - index_a);
			while (move-- > 0)
			{
				r_rotate(stack_b);
				ft_putstr_fd("rrb", FD);
			}
		}
		if ((length_a - index_a) > (length_b - target_a))
		{
			move = (length_a - index_a) - (length_b - target_a);
			while (move-- > 0)
			{
				r_rotate(stack_a);
				ft_putstr_fd("rra", FD);
			}
		}
	}
	else
	{
		// pile A
		if (index_a <= mediane_a)
		{
			while (index_a-- > 0)
			{
				rotate(stack_a);
				ft_putstr_fd("ra", FD);
			}
		}
		else if (index_a > mediane_a)
		{
			index_a = length_a - index_a;
			while (move-- > 0)
			{
				r_rotate(stack_a);
				ft_putstr_fd("rra", FD);
			}
		}
		// PILE B
		if (target_a <= mediane_b)
		{
			while (target_a-- > 0)
			{
				rotate(stack_b);
				ft_putstr_fd("rb", FD);
			}
		}
		else if (target_a > mediane_b)
		{
			move = length_b - target_a;
			while (move-- > 0)
			{
				r_rotate(stack_b);
				ft_putstr_fd("rrb", FD);
			}
		}
	}
	push(stack_a, stack_b);
	ft_putstr_fd("pb", FD);
	insert_target_index(stack_a, stack_b);
}
