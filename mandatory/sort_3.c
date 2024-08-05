/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:34:02 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/31 11:34:16 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max_value;

	if (is_asc(*a))
		return ;
	max_value = get_value_max(*a);
	if (*a == max_value)
		exec_move(rotate, a, "ra", 1);
	else if ((*a)->next == max_value)
		exec_move(r_rotate, a, "rra", 1);
	if (!is_asc(*a))
		exec_move(swap, a, "sa", 1);
}
