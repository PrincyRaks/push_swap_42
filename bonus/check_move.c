/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:34:01 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/07 11:33:29 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>

int	check_move(const char *move)
{
	if (!(ft_strncmp("sa\n", move, 3)))
		return (1);
	else if (!(ft_strncmp("sb\n", move, 3)))
		return (1);
	else if (!(ft_strncmp("ss\n", move, 3)))
		return (1);
	else if (!(ft_strncmp("ra\n", move, 3)))
		return (1);
	else if (!(ft_strncmp("rb\n", move, 3)))
		return (1);
	else if (!(ft_strncmp("rr\n", move, 3)))
		return (1);
	else if (!(ft_strncmp("rra\n", move, 4)))
		return (1);
	else if (!(ft_strncmp("rrb\n", move, 4)))
		return (1);
	else if (!(ft_strncmp("rrr\n", move, 4)))
		return (1);
	else if (!(ft_strncmp("pa\n", move, 3)))
		return (1);
	else if (!(ft_strncmp("pb\n", move, 3)))
		return (1);
	return (0);
}

void	exec_instrc(const char *move, t_stack **a, t_stack **b)
{
	if (!(ft_strncmp("rra", move, 3)))
		r_rotate(a);
	else if (!(ft_strncmp("rrb", move, 3)))
		r_rotate(b);
	else if (!(ft_strncmp("rrr", move, 3)))
		both_move(r_rotate, a, b);
	else if (!(ft_strncmp("sa", move, 2)))
		swap(a);
	else if (!(ft_strncmp("sb", move, 2)))
		swap(b);
	else if (!(ft_strncmp("ss", move, 2)))
		both_move(swap, a, b);
	else if (!(ft_strncmp("ra", move, 2)))
		rotate(a);
	else if (!(ft_strncmp("rb", move, 2)))
		rotate(b);
	else if (!(ft_strncmp("rr", move, 2)))
		both_move(rotate, a, b);
	else if (!(ft_strncmp("pb", move, 2)))
		push(a, b);
	else if (!(ft_strncmp("pa", move, 2)))
		push(b, a);
}

void	treatment_move(char *data, t_stack **a, t_stack **b)
{
	char	**move;
	int		len_tab;
	int		i;

	move = ft_split(data);
	free(data);
	if (!move)
	{
		free(move);
		return ;
	}
	len_tab = strlen_tab(move);
	i = -1;
	while (len_tab > ++i)
		exec_instrc(move[i], a, b);
	i = -1;
	while (len_tab > ++i)
		free(move[i]);
	free(move);
	if ((*a && is_asc(*a)) && !count_node(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	both_move(void (*move)(t_stack **), t_stack **a, t_stack **b)
{
	move(a);
	move(b);
}
