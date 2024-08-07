/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:02:05 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/06 14:02:07 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!memory)
		memory = ft_calloc_input(1, sizeof(char));
	if (!memory)
		return (NULL);
	buffer = ft_calloc_input((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(memory), NULL);
	memory = read_fd(fd, memory, buffer);
	if (!memory)
		return (NULL);
	buffer = extract_line(memory);
	memory = realloc_after_line(memory);
	if (!memory)
		return (free(buffer), NULL);
	return (buffer);
}

void	free_all(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*read_fd(int fd, char *storage, char *buffer)
{
	ssize_t	nread;

	nread = BUFFER_SIZE;
	while (nread == BUFFER_SIZE && !(ft_findchr(storage, '\n')))
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread < 0)
			return (free_all(buffer, storage), NULL);
		buffer[nread] = 0;
		storage = ft_strjoin_input(storage, buffer);
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char *memory)
{
	ssize_t	i;
	char	*new_line;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i = i + 1;
	new_line = ft_calloc_input((i + 1), sizeof(char));
	if (!new_line)
		return (free(memory), NULL);
	new_line[i] = 0;
	i--;
	while (i >= 0)
	{
		new_line[i] = memory[i];
		i--;
	}
	return (new_line);
}

char	*realloc_after_line(char *memory)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i] && i == 0)
		return (free(memory), NULL);
	new = ft_calloc_input((ft_strlen(memory) - i) + 1, sizeof(char));
	if (!new)
		return (free(memory), NULL);
	j = 0;
	i += (memory[i] == '\n');
	while (memory[i])
	{
		new[j] = memory[i];
		j++;
		i++;
	}
	free(memory);
	return (new);
}
