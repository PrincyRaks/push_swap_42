/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:20:24 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 14:00:11 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*check_dup(char **data, int size)
{
	long	*number;

	number = convert_int(data, size);
	if (!not_dup(number, size))
	{
		print_error();
		free(data);
		free(number);
	}
	return (number);
}

long	*convert_int(char **str, int size)
{
	long	*tab_n;
	int		i;

	tab_n = (long *)malloc(sizeof(long) * size);
	if (!tab_n)
		return (free(str), NULL);
	i = 0;
	while (str[i])
	{
		tab_n[i] = ft_atoi(str[i]);
		if (tab_n[i] > 2147483647 || tab_n[i] < -2147483648)
		{
			print_error();
			free(str);
			return (free(tab_n), NULL);
		}
		i++;
	}
	free(str);
	return (tab_n);
}

char	*join_argv(char **argv)
{
	int		i;
	char	*data;

	i = 1;
	data = ft_calloc(1, 1);
	while (argv[i])
	{
		data = ft_strjoin_data(data, argv[i++]);
		if (!data)
			print_error();
	}
	if (!check_number(data))
	{
		print_error();
		free(data);
	}
	return (data);
}

t_stack	*init_stack(long *tab_num, int size)
{
	int		i;
	t_stack	*lst;

	i = 0;
	lst = NULL;
	while (i < size)
	{
		ft_lstadd_back(&lst, create_node((int)tab_num[i], i));
		i++;
	}
	add_top_bottom(&lst, ft_lstlast(lst));
	free(tab_num);
	return (lst);
}

t_stack	*init_data(char **argv)
{
	int		i;
	char	*data;
	char	**tab_str;
	t_stack	*lst;

	i = 1;
	data = join_argv(argv);
	tab_str = ft_split(data);
	if (!tab_str)
	{
		free(tab_str);
		return (NULL);
	}
	i = strlen_tab(tab_str);
	lst = init_stack(check_dup(tab_str, i), i);
	return (lst);
}
