/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:38:00 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 13:51:52 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

int	get_target_index(t_stack *node_a, t_stack *first_b)
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

int	median(int length)
{
	int	result;

	result = length;
	if (result % 2 != 0)
		return ((result / 2) + 1);
	return (result / 2);
}

int	cost_both(int index, int target, int len_a, int len_b)
{
	int	median_a;
	int	median_b;

	median_a = median(len_a);
	median_b = median(len_b);
	if (index <= median_a && target <= median_b)
	{
		if (index >= target)
			return (index + 1);
		return (target + 1);
	}
	if (index > median_a && target > median_b)
	{
		if ((len_a - index) >= (len_b - target))
			return (len_a - index + 1);
		return (len_b - target + 1);
	}
	return (0);
}

int	cost_individual(int index, int len)
{
	int	med;

	med = median(len);
	if (index < med)
		return (index);
	return (len - index);
}

int	cost_node(t_stack *node_a, t_stack *first_b, int len_a, int len_b)
{
	int	cost_1;
	int	cost_2;
	int	target_i;

	target_i = get_target_index(node_a, first_b);
	cost_1 = cost_both(node_a->index, target_i, len_a, len_b);
	if (cost_1 > 0)
		return (cost_1);
	cost_1 = cost_individual(node_a->index, len_a);
	cost_2 = cost_individual(target_i, len_b);
	return (cost_1 + cost_2 + 1);
}
