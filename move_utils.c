/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/10 09:59:00 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/10 15:32:22 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	swap(t_stack **first)
{
	t_stack *node_next;
	t_stack *node_next_next;

	if ((!first || !*first) || (*first)->top == (*first)->bottom)
		return ;
	node_next = (*first)->next;
	node_next_next = (*first)->next->next;
	node_next->next = *first;
	*first = node_next;
	(*first)->next->next = node_next_next;
	add_top_bottom(first, ft_lstlast(*first));
}

void	rotate(t_stack **first)
{
	t_stack *tmp;

	if ((!first || !*first) || (*first)->top == (*first)->bottom)
		return ;
	if (count_node(*first) == 2)
	{
		swap(first);
		return ;
	}
	tmp = *first;
	*first = (*first)->next;
	(*first)->bottom->next = tmp;
	tmp->next = NULL;
	add_top_bottom(first, ft_lstlast(*first));
}

void	r_rotate(t_stack **first)
{
	t_stack *tmp;
	int len;

	if ((!first || !*first) || (*first)->top == (*first)->bottom)
		return ;
	len = count_node(*first);
	if (len == 2)
	{
		swap(first);
		return ;
	}
	(*first)->bottom->next = *first;
	*first = (*first)->bottom;
	tmp = *first;
	while (0 < (len - 1))
	{
		tmp = tmp->next;
		len--;
	}
	tmp->next = NULL;
	add_top_bottom(first, ft_lstlast(*first));
}

void	push(t_stack **send, t_stack **receive)
{
	t_stack *first_send;
	t_stack	*new_first;
	
	if ((!send || !receive) && !*send)
		return ;
	new_first = (*send)->next;
	first_send = create_node((*send)->value);
	free(*send);
	if (!*receive)
		*receive = first_send;
	else if (*receive != NULL)
		add_front(receive, first_send);
	*send = new_first;
	add_top_bottom(send, ft_lstlast(*send));
	add_top_bottom(receive, ft_lstlast(*receive));
}