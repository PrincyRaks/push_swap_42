/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:31:47 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/01 14:44:47 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap(t_stack **first)
{
	t_stack	*node_next;
	t_stack	*node_next_next;

	if ((!first || !*first) || !(*first)->next)
		return ;
	node_next = (*first)->next;
	node_next_next = (*first)->next->next;
	node_next->next = *first;
	*first = node_next;
	(*first)->next->next = node_next_next;
	load_stack(first);
}

void	rotate(t_stack **first)
{
	t_stack	*tmp;

	if ((!first || !*first) || !(*first)->next)
		return ;
	tmp = *first;
	*first = (*first)->next;
	ft_lstlast(*first)->next = tmp;
	tmp->next = NULL;
	load_stack(first);
}

void	r_rotate(t_stack **first)
{
	t_stack	*tmp;
	t_stack	*last_node;
	int		len;

	if ((!first || !*first) || !(*first)->next)
		return ;
	len = count_node(*first);
	last_node = ft_lstlast(*first);
	last_node->next = *first;
	*first = last_node;
	tmp = *first;
	while (0 < (len - 1))
	{
		tmp = tmp->next;
		len--;
	}
	tmp->next = NULL;
	load_stack(first);
}

void	push(t_stack **send, t_stack **receive)
{
	t_stack	*new_first;

	if (!send || !receive || !*send)
		return ;
	new_first = (*send)->next;
	if (!*receive)
	{
		*receive = *send;
		(*receive)->next = NULL;
	}
	else if (*receive != NULL)
		add_front(receive, *send);
	*send = new_first;
	load_stack(send);
	load_stack(receive);
}

void	pb(t_stack **send, t_stack **receive)
{
	push(send, receive);
	ft_putstr_fd("pb");
}
