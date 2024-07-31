/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:32:40 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/31 11:34:54 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int number, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index = index;
	node->value = number;
	node->next = NULL;
	return (node);
}

void	load_stack(t_stack **stack)
{
	int		i;
	t_stack	*node;

	if (!*stack)
		return ;
	node = *stack;
	i = 0;
	while (node->next)
	{
		node->index = i;
		node = node->next;
		i++;
	}
	node->index = i;
}

t_stack	*get_value_max(t_stack *first)
{
	t_stack	*max;

	if (!first)
		return (NULL);
	max = first;
	while (first)
	{
		if (max->value < first->value)
			max = first;
		first = first->next;
	}
	return (max);
}

t_stack	*get_value_min(t_stack *first)
{
	t_stack	*min;

	if (!first)
		return (NULL);
	min = first;
	while (first)
	{
		if (min->value > first->value)
			min = first;
		first = first->next;
	}
	return (min);
}
