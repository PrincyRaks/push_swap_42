/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:30:47 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/09 15:22:22 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static char	*ft_strjoin_data(char *s1, char *s2)
{
	char	*new_s;
	char	*tmp_s1;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = ft_calloc((len + 2), 1);
	if (!new_s)
		return (free(s1), NULL);
	tmp_s1 = s1;
	while (*tmp_s1)
		*(new_s++) = *(tmp_s1++);
	if (s1)
        *(new_s++) = ' ';
	while (*s2)
		*(new_s++) = *(s2++);
	free(s1);
	return (new_s - len - 1);
}

static int check_dup(char *s)
{
    
}

static int	check_number(char *s)
{
    int i;

    i = 0;
    while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i] >= '0' && s[i] <= '9')
        i++;
}

char	*check_input(char **argv)
{
	int i;
	int len;
	char *data;

	i = 1;
	data = ft_calloc(1, 1);
	while (argv[i])
		data = ft_strjoin_data(data, argv[i++]);
	return (data);
}