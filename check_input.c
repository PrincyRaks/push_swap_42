/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:24:47 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/25 13:24:47 by rrakotos         ###   ########.fr       */
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

int	is_empty(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strjoin_data(char *s1, char *s2)
{
	char	*new_s;
	char	*tmp_s1;
	size_t	len;

	if (is_empty(s2))
		return (free(s1), NULL);
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

int	not_dup(long *number, int size)
{
	int		i;
	int		j;
	int		count;
	long	*dup;

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
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((!ft_isdigit(s[i]) && !ft_isspace(s[i])) && (s[i] != '-'
				&& s[i] != '+'))
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