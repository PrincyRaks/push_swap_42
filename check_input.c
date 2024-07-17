/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/09 13:30:47 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/12 16:56:22 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


int	strlen_tab(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

char	*ft_strjoin_data(char *s1, char *s2)
{
	char *new_s;
	char *tmp_s1;
	size_t len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (*s1 && *s2)
		len++;
	new_s = ft_calloc((len + 1), 1);
	if (!new_s)
		return(free(s1), NULL);
	tmp_s1 = s1;
	while (*tmp_s1)
		*(new_s++) = *(tmp_s1++);
	if (*s1 && *s2)
		*(new_s++) = 32;
	while (*s2)
		*(new_s++) = *(s2++);
	free(s1);
	return (new_s - len);
}

long	*convert_int(char **str, int size)
{
	long *tab_n;
	int i;

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

int	not_dup(long *number, int size)
{
	int i;
	int j;
	int count;
	long *dup;

	i = 0;
	dup = number;
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (number[i] == dup[j])
				count++;
			j++;
		}
		if (count >= 2)
			return (0);
		i++;
	}
	return (1);
}

int	check_number(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((!ft_isdigit(s[i]) && !ft_isspace(s[i])) 
			&& (s[i] != '-' && s[i] != '+'))
			return (0);
		while (ft_isspace(s[i]))
			i++;
		if (s[i] == '-' || s[i] == '+')
		{
			i++;
			if (s[i] >= 48 && s[i] <= 57)
				check_number(s + i);
			else
				return (0);
		}
		while (s[i] >= 48 && s[i] <= 57)
			i++;
	}
	return (1);
}

long	*check_dup(char **data, int size)
{
	long *number;

	number = convert_int(data, size);
	if (!not_dup(number, size))
	{
		print_error();
		free(data);
		free(number);
	}
	return (number);
}

t_stack	*init_data(char **argv)
{
	int i;
	char *data;
	char **tab_str;
	t_stack *lst;

	i = 1;
	data = ft_calloc(1, 1);
	while (argv[i])
		data = ft_strjoin_data(data, argv[i++]);
	if (!check_number(data))
	{
		print_error();
		free(data);
	}
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
