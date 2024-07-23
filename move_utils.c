/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:28:10 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/22 10:28:10 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// void	print_move(char *move, char stack)
// {
// 	write (1, move, ft_strlen(move));
// 	write (1, &stack, 1);
// 	write (1 , "\n", 1);
// }

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
	load_stack(first);
}

void	rotate(t_stack **first)
{
	t_stack *tmp;

	if ((!first || !*first) || (*first)->top == (*first)->bottom)
		return ;
	// if (count_node(*first) == 2)
	// {
	// 	swap(first, c);
	// 	return ;
	// }
	tmp = *first;
	*first = (*first)->next;
	(*first)->bottom->next = tmp;
	tmp->next = NULL;
	load_stack(first);
}

void	r_rotate(t_stack **first)
{
	t_stack *tmp;
	int len;

	if ((!first || !*first) || (*first)->top == (*first)->bottom)
		return ;
	len = count_node(*first);
	// if (len == 2)
	// {
	// 	swap(first, c);
	// 	return ;
	// }
	(*first)->bottom->next = *first;
	*first = (*first)->bottom;
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
	
	if ((!send || !receive) && !*send)
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