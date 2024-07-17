/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:21:20 by rrakotos          #+#    #+#             */
/*   Updated: 2024/03/11 09:47:37 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s)
{
	size_t	len;

	if (!*s)
		return (0);
	len = 0;
	while (*s)
	{
		while (*s == 32 || (*s >= 9 && *s <= 13))
			s++;
		if (*s)
			len++;
		while ((*s != 32 && *s) && (*s < 9 || *s > 13))
			s++;
	}
	return (len);
}

static char	*store_word(char const *start)
{
	char	*word;
	size_t	len_w;
	size_t	i;

	len_w = 0;
	if (ft_strchr(start))
		len_w = ft_strchr(start) - start;
	else
		len_w = ft_strlen(start);
	word = (char *)malloc(sizeof(char) * (len_w + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_w)
	{
		word[i] = ((char *)start)[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s)
{
	char	**list_w;
	size_t	i;

	list_w = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (!list_w)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == 32 || (*s >= 9 && *s <= 13))
			s++;
		if (*s)
		{
			list_w[i] = store_word(s);
			if (!list_w[i])
				free(list_w);
			i++;
		}
		while ((*s != 32 && *s) && (*s < 9 || *s > 13))
			s++;
	}
	list_w[i] = NULL;
	return (list_w);
}
