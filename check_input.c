/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:30:47 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/12 16:56:22 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	strlen_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

char	*ft_strjoin_data(char *s1, char *s2)
{
	char	*new_s;
	char	*tmp_s1;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (*s1 && *s2)
		len++;
	new_s = ft_calloc((len + 1), 1);
	if (!new_s)
		return (free(s1), NULL);
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

long	*convert_int(char *str)
{
	char	**tab_s;
	long	*tab_n;
	int		i;

	tab_s = ft_split(str);
	tab_n = (long *)malloc(sizeof(long) * strlen_tab(tab_s));
	if (!tab_n)
		return (0);
	i = 0;
	while (tab_s[i] != NULL)
	{
		tab_n[i] = ft_atoi(tab_s[i]);
		if (tab_n[i] > 2147483647 || tab_n[i] < -2147483648)
			print_error();
		i++;
	}
	return (tab_n);
}

int	not_dup(long *number)
{
	int		i;
	int		j;
	int		count;
	long	*dup;

	i = 0;
	dup = number;
	while (number[i])
	{
		j = 0;
		count = 0;
		while (dup[j])
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
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]))
			return (0);
		while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
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

long	*check_input(char **argv)
{
	int		i;
	char	*data;
	long	*number;

	i = 1;
	data = ft_calloc(1, 1);
	while (argv[i])
		data = ft_strjoin_data(data, argv[i++]);
	if (!check_number(data))
		print_error();
	number = convert_int(data);
	if (!not_dup(number))
		print_error();
	return (number);
}
