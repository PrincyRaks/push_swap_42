/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:34:01 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/05 17:22:48 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>

int check_move(const char *move, int len)
{
    if (!(ft_strncmp("sa\n", move, len)))
        return (1);
    else if (!(ft_strncmp("sb\n", move, len)))
        return (1);
    else if (!(ft_strncmp("ss\n", move, len)))
        return (1);
    else if (!(ft_strncmp("ra\n", move, len)))
        return (1);
    else if (!(ft_strncmp("rb\n", move, len)))
        return (1);
    else if (!(ft_strncmp("rr\n", move, len)))
        return (1);
    else if (!(ft_strncmp("rra\n", move, len)))
        return (1);
    else if (!(ft_strncmp("rrb\n", move, len)))
        return (1);
    else if (!(ft_strncmp("rrr\n", move, len)))
        return (1);
    else if (!(ft_strncmp("pa\n", move, len)))
        return (1);
    else if (!(ft_strncmp("pb\n", move, len)))
        return (1);    
    return (0);
}

void    exec_instrc(const char *move, t_stack **a, t_stack **b)
{
    int len;

    len = ft_strlen(move);
    if (!(ft_strncmp("sa\n", move, len)))
        swap(a);
    else if (!(ft_strncmp("sb\n", move, len)))
        swap(b);
    else if (!(ft_strncmp("ss\n", move, len)))
        both_move(swap, a, b);
    else if (!(ft_strncmp("ra\n", move, len)))
        rotate(a);
    else if (!(ft_strncmp("rb\n", move, len)))
        rotate(b);
    else if (!(ft_strncmp("rr\n", move, len)))
        both_move(rotate, a, b);
    else if (!(ft_strncmp("rra\n", move, len)))
        r_rotate(a);
    else if (!(ft_strncmp("rrb\n", move, len)))
        r_rotate(b);
    else if (!(ft_strncmp("rrr\n", move, len)))
        both_move(r_rotate, a, b);
    else if (!(ft_strncmp("pb\n", move, len)))
        push(a, b);
    else if (!(ft_strncmp("pa\n", move, len)))
        push(b, a);
}

void    treatment_move(char *data, t_stack **a, t_stack **b)
{
    char    **move;
    int     len_tab;
    int     i;

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
    if (is_asc(*a))
        write (1, "OK\n", 3);
    else
        write (1, "KO\n", 3);
}

void    both_move(void (*move)(t_stack **), t_stack **a, t_stack **b)
{
    move(a);
    move(b);
}