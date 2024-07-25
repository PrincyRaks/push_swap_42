/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:37:11 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 16:33:35 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return number of ra
// int sortable(t_stack *a)
// {
//     t_stack *node_min;
//     t_stack *node_top;
    
//     node_min = ;
//     node_top = ;
//     // ambany node_min is_asc
//     // ambany node_top is asc jusqu'a node_min
// }

void    push_swap(t_stack **a, t_stack **b)
{
    int len_a;

    len_a = count_node(*a);
    if (len_a < 3 && !is_asc(*a))
        exec_move(swap, a, "sa", 1);
    else if (len_a == 3 && !is_asc(*a))
        sort_three(a);
    else if (len_a > 3 && sortable())
        // tant que is_asc(*a) -> false => exec_move(rotate, ra, a, sortable());
    // else if (len_a > 3 && !sortable())  
        // mouvement ao anaty main no ataony
}

// sort_stack(t_stack **a)
// {
//     t_stack **b;
//     int i;

//     b = (t_stack**)malloc(sizeof(t_stack*));
//     if (!b)
//         return (free(a), NULL);
//     // push 3 e !
//     i = 3;
//     while (i-- > 0)
//         push(a, b, 'b');
//     // algo_range(a, b);
// }