/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:36:08 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/12 16:32:26 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// add data from long* to t_stack
t_stack	*init_stack(long *tab_num)
{
	int		i;
	t_stack	*lst;

	i = 0;
	while (tab_num[i])
	{
		ft_lstadd_back(&lst, create_node((int)tab_num[i], i));
		i++;
	}
	return (lst);
}
t_stack	*create_node(int number, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = number;
	node->index = index;
	node->next = NULL;
	return (node);
}
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*end;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			while (*lst)
			{
				if (!(*lst)->next)
					end = *lst;
				*lst = (*lst)->next;
			}
			end->next = new;
		}
	}
}
// // range index ,top and bottom ...
void	load_stack(t_stack *stack)
{
}
