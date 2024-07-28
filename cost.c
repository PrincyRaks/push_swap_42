/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:12:26 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 15:18:22 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	cost_both(int index, int target, int len_1, int len_2)
{
	int	median_1;
	int	median_2;

	median_1 = median(len_1);
	median_2 = median(len_2);
	if (index <= median_1 && target <= median_2)
	{
		if (index >= target)
			return (index + 1);
		return (target + 1);
	}
	if (index > median_1 && target > median_2)
	{
		if ((len_1 - index) >= (len_2 - target))
			return (len_1 - index + 1);
		return (len_2 - target + 1);
	}
	return (0);
}

int	cost_individual(int index, int len)
{
	int	med;

	med = median(len);
	if (index < med)
		return (index);
	return (len - index);
}

int	cost_node_a(t_stack *node_a, t_stack *first_b, int len_a, int len_b)
{
	int	cost_1;
	int	cost_2;
	int	target_a;

	target_a = target_min_index(node_a, first_b);
	cost_1 = cost_both(node_a->index, target_a, len_a, len_b);
	if (cost_1 > 0)
		return (cost_1);
	cost_1 = cost_individual(node_a->index, len_a);
	cost_2 = cost_individual(target_a, len_b);
	return (cost_1 + cost_2 + 1);
}

int	cost_node_b(t_stack *node_b, t_stack *first_a, int len_b, int len_a)
{
	int	cost_1;
	int	cost_2;
	int	target_b;

	target_b = target_max_index(node_b, first_a);
	cost_1 = cost_both(node_b->index, target_b, len_b, len_a);
	if (cost_1 > 0)
		return (cost_1);
	cost_1 = cost_individual(node_b->index, len_b);
	cost_2 = cost_individual(target_b, len_a);
	return (cost_1 + cost_2 + 1);
}