/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:12:36 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/10 09:54:24 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*memory;

	memory = malloc(elementCount * elementSize);
	if (!memory)
		return (NULL);
	ft_bzero(memory, elementCount * elementSize);
	return (memory);
}
