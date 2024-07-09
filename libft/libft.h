/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:41:46 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/09 16:16:29 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>

long	ft_atoi(const char *nptr);
int		ft_isdigit(int c);
char	**ft_split(char const *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);

#endif