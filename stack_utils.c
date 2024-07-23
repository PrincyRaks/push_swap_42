/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:28:39 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/22 10:28:39 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


t_stack	*init_stack(long *tab_num, int size)
{
	int i;
	t_stack *lst;

	i = 0;
	lst = NULL;
	while (i < size)
	{
		ft_lstadd_back(&lst, create_node((int)tab_num[i], i));
		i++;
	}
	add_top_bottom(&lst, ft_lstlast(lst));
	free(tab_num);
	return (lst);
}

int	count_node(t_stack *lst)
{
	int i;

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
	t_stack *end;

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

void	add_top_bottom(t_stack **lst, t_stack *tail)
{
	t_stack *node;
	t_stack *head;

	head = node = *lst;
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

void	add_front(t_stack **lst, t_stack *node)
{
	if (lst && node)
	{
		node->next = *lst;
		*lst = node;
	}
}

void	load_stack(t_stack **stack)
{
	unsigned int i;
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