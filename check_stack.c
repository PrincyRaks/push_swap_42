/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:42:18 by marvin            #+#    #+#             */
/*   Updated: 2024/07/16 22:42:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_range(t_stack *first)
{
    while(first)
    {
        // ts mety ty condition ty !
        if (first->value > first->next->value)
            return (0);
        first = first->next;
    }
    return (1);
}