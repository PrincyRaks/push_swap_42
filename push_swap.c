/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:37:11 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/26 15:52:00 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortable(t_stack *a)
{
	t_stack	*node_min;
	t_stack	*node_top;
	int		nb;

	nb = 0;
	node_min = get_value_min(a);
	node_top = a->top;
	if (!is_asc(node_min))
		return (0);
	// RAH ITY 7 6 8 9 2 3 4 5
	// if ((node_top->value > node_top->next->value) &&node_top->top)
	//     exec_move(swap, a, "sa", 1);
	while (node_top->next && (node_top != node_min))
	{
		if (node_top->next != node_min
			&& node_top->value > node_top->next->value)
			return (0);
		node_top = node_top->next;
		nb++;
	}
	return (nb);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	// t_stack	**b;
	int		i;

	// b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
	{
		free(a);
		exit(1);
	}
	i = 2;
	while (i-- > 0)
	{
		push(a, b);
		ft_putstr_fd("pb");
	}
	if ((is_max(*a, *b) || is_min(*a, *b)) && !is_desc(*b))
		exec_move(swap, b, "sb", 1);
	push(a, b);
	ft_putstr_fd("pb");
    range_algo(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;
	int	move;

	len_a = count_node(*a);
	move = sortable(*a);
	if (len_a == 2 && !is_asc(*a))
		exec_move(swap, a, "sa", 1);
	else if (len_a == 3 && !is_asc(*a))
		sort_three(a);
	else if (len_a > 3 && move > 0)
		exec_move(rotate, a, "ra", move);
	else if (len_a > 3 && move <= 0)
		sort_stack(a, b);
}
