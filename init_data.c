/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:20:24 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 15:27:35 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*check_dup(char **data, int size)
{
	long	*number;

	number = convert_int(data, size);
	if (!not_dup(number, size))
	{
		free(data);
		free(number);
		print_error();
	}
	return (number);
}

long	*convert_int(char **str, int size)
{
	long	*tab_n;
	int		i;

	tab_n = (long *)malloc(sizeof(long) * size);
	if (!tab_n)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tab_n[i] = ft_atoi(str[i]);
		if (tab_n[i] > 2147483647 || tab_n[i] < -2147483648)
		{
			free(str);
			free(tab_n);
			print_error();
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
	if (!data)
		print_error();
	while (argv[i])
	{
		data = ft_strjoin_data(data, argv[i]);
		if (!data)
			print_error();
		i++;
	}
	if (!check_number(data))
	{
		free(data);
		print_error();
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
		ft_lstadd_back(&lst, create_node(tab_num[i], i));
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