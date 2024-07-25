/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:32:40 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 15:35:59 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int number,int index)
{
	t_stack *node;

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
	int i;
	t_stack *node;

	node = *stack;
	i = 0;
	while (node->next)
	{
		node->index = i;
		node = node->next;
		i++;
	}
	node->index = i;
	add_top_bottom(stack, node);
}