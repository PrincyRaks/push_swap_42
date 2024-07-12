/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:31:05 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/12 16:57:53 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*lst;
	char	*data;
	int		i;
	long	*number;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
			data = ft_strjoin_data(data, argv[i++]);
		// if (!check_number(data))
		// 	print_error();
		// number = convert_int(data);
		// if (!not_dup(number))
		// 	print_error();
		// lst = init_stack(number);
		// while (lst)
		// {
		// 	printf("value: %d et index: %d \n", lst->value, lst->index);
		// 	lst = lst->next;
		// }
		printf("HH");
	}
	return (0);
}
