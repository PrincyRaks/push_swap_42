/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:12:12 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 13:12:12 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_asc(t_stack *first)
{
	while (first->next)
	{
		if (first->value > first->next->value)
			return (0);
		first = first->next;
	}
	return (1);
}

int	is_desc(t_stack *first)
{
	while (first->next)
	{
		if (first->value < first->next->value)
			return (0);
		first = first->next;
	}
	return (1);
}

int	is_max(t_stack *node, t_stack *first)
{
	while (first)
	{
		if (node->value < first->value)
			return (0);
		first = first->next;
	}
	return (1);
}

int	is_min(t_stack *node, t_stack *first)
{
	while (first)
	{
		if (node->value > first->value)
			return (0);
		first = first->next;
	}
	return (1);
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