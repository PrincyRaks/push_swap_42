/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:31:05 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/09 13:57:08 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int argc, char **argv)
// {
//     if (argc > 1)
//     {

//     }
//     return (0);
// }

#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    printf("%s\n", check_input(argv));
    return (0);
}