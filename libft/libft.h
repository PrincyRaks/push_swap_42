/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:45:22 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/31 10:45:22 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

# ifndef FD
#  define FD 1
# endif

long	ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isspace(char c);
char	**ft_split(char const *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
void	ft_putstr_fd(char *s);

#endif
