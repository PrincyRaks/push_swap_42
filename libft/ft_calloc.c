/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:12:36 by rrakotos          #+#    #+#             */
/*   Updated: 2024/03/11 10:28:13 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*memory;

	memory = malloc(elementCount * elementSize);
	if (!memory)
		return (NULL);
	ft_bzero(memory, elementCount * elementSize);
	return (memory);
}
