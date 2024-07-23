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

unsigned int	median(unsigned int length)
{
	unsigned int	result;

	result = length;
	if (result % 2 != 0)
		return ((result / 2) + 1);
	return (result / 2);
}

int	same_level(int index, int target_i, int len_a, int len_b)
{
	int	median_a;
	int	median_b;

	median_a = median((unsigned int)len_a);
	median_b = median((unsigned int)len_b);
	if (index <= median_a && target_i <= median_b)
	{
		if (index >= target_i)
			return (index + 1);
		return (target_i + 1);
	}
	if (index > median_a && target_i > median_b)
	{
		if ((len_a - index) >= (len_b - target_i))
			return (len_a - index + 1);
		return (len_b - target_i + 1);
	}
	return (0);
}

int	cost_individual(int	index, int len)
{
	unsigned int	med;

	med = median((unsigned int)len);
	if (index < med)
		return (index);
	return (len - index);
}

int	cost_node(t_stack *node_a, t_stack *first_b, int len_a, int len_b)
{
	unsigned int	cost_1;
	unsigned int	cost_2;
	unsigned int	target_i;

	target_i = get_target_index(node_a, first_b);
    cost_1 = (unsigned int)same_level(node_a->index, (int)target_i, len_a, len_b);
    if (cost_1 > 0)
        return (cost_1);
	cost_1 = (unsigned int)cost_individual(node_a->index, len_a);
	cost_2 = (unsigned int)cost_individual(target_i, len_b);
	return ((int)(cost_1 + cost_2 + 1));
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
	min_cost = cost_node(a, *first_b, len_a, len_b);
	while (a)
	{
		if (min_cost > cost_node(a, *first_b,len_a, len_b))
		{
			min_cost = cost_node(a, *first_b,len_a, len_b);
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
	unsigned int	median_a;
	unsigned int	median_b;
	unsigned int	index_a;
	unsigned int	target_a;
	unsigned int	move;

	median_a = median(length_a);
	median_b = median(length_b);
	index_a = to_range->index;
	target_a = to_range->target_index;
	// r
	if (index_a <= median_a && target_a <= median_b)
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
	else if (index_a > median_a && target_a > median_b)
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
		if (index_a <= median_a)
		{
			while (index_a-- > 0)
			{
				rotate(stack_a);
				ft_putstr_fd("ra", FD);
			}
		}
		else if (index_a > median_a)
		{
			index_a = length_a - index_a;
			while (move-- > 0)
			{
				r_rotate(stack_a);
				ft_putstr_fd("rra", FD);
			}
		}
		// PILE B
		if (target_a <= median_b)
		{
			while (target_a-- > 0)
			{
				rotate(stack_b);
				ft_putstr_fd("rb", FD);
			}
		}
		else if (target_a > median_b)
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
	// insert_target_index(stack_a, stack_b);
}
