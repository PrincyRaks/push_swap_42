/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:32:28 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 15:32:28 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	count_node(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
			end = ft_lstlast(*lst);
			if (end)
				end->next = new;
		}
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	add_front(t_stack **lst, t_stack *node)
{
	if (lst && node)
	{
		node->next = *lst;
		*lst = node;
	}
}

void	add_top_bottom(t_stack **lst, t_stack *tail)
{
	t_stack	*node;
	t_stack	*head;

	head = *lst;
	node = *lst;
	if (lst)
	{
		if (*lst)
		{
			while (node)
			{
				node->top = head;
				node->bottom = tail;
				node = node->next;
			}
		}
	}
}
