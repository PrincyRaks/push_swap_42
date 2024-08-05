/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:07:16 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/01 15:07:16 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	*check_dup(char **data, int size)
{
	static long	*number;

	number = convert_int(data, size);
	if (!not_dup(number, size))
	{
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
			while (size-- != 0)
				free(str[size]);
			free(str);
			free(tab_n);
			print_error();
		}
		i++;
	}
	while (size-- != 0)
		free(str[size]);
	free(str);
	return (tab_n);
}

static char	*join_argv(char **argv)
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

static t_stack	*init_stack(long *tab_num, int size)
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
	free(data);
	if (!tab_str)
	{
		free(tab_str);
		return (NULL);
	}
	i = strlen_tab(tab_str);
	lst = init_stack(check_dup(tab_str, i), i);
	return (lst);
}
