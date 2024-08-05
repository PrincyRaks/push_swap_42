/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:06:04 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/31 17:21:24 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_min_index(t_stack *node_a, t_stack *first_b)
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

int	target_max_index(t_stack *node_b, t_stack *first_a)
{
	t_stack	*max_index;
	t_stack	*stack_a;

	max_index = NULL;
	stack_a = first_a;
	while (first_a)
	{
		if ((node_b->value < first_a->value) && (max_index == NULL
				|| first_a->value < max_index->value))
			max_index = first_a;
		first_a = first_a->next;
	}
	if (!max_index)
		return ((get_value_min(stack_a))->index);
	return (max_index->index);
}
