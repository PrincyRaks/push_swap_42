/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:24:02 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/05 16:59:24 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*instrc;
	t_stack	*a;
	t_stack	*b;
	char	*data;

	if (argc > 1)
	{
		a = init_data(argv);
		b = NULL;
		data = ft_calloc(1, 1);
		instrc = get_next_line(0);
		while (instrc)
		{
			if (!check_move(instrc, ft_strlen(instrc)))
				print_error();
			data = ft_strjoin_data(data, instrc);
			instrc = get_next_line(0);
		}
		treatment_move(data, &a, &b);
		// free_list(&a);
		// free_list(&b);
	}
	return (0);
}
