/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:54:15 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/01 11:48:19 by rrakotos         ###   ########.fr       */
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

int	not_dup(long *number, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				count;
	long			*dup;

	i = 0;
	dup = number;
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (number[i] == dup[j])
			{
				count++;
				if (count > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_number(char *s)
{
	int	found_digit;

	while (*s != '\0')
	{
		while (ft_isspace(*s))
			s++;
		if (*s == '-' || *s == '+')
			s++;
		found_digit = 0;
		while (ft_isdigit(*s))
		{
			found_digit = 1;
			s++;
		}
		if (!*s)
			break;
		if (!ft_isspace(*s) || !found_digit)
			return (0);
		while (ft_isspace(*s))
            s++;
		if (*s != '\0' && *s != '-' && *s != '+' && !ft_isdigit(*s))
			return (0);
	}
	return (1);
}
