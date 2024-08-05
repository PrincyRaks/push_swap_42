/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:52:08 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/05 16:16:52 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mandatory/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_findchr(char *s, int c);
void    *ft_calloc_input(size_t elementCount, size_t elementSize);
char    *ft_strjoin_input(char *s1, char *s2);
char    *ft_findchr(char *s, int c);
char	*get_next_line(int fd);
void	free_all(char *s1, char *s2);
char	*read_fd(int fd, char *storage, char *buffer);
char	*extract_line(char *memory);
char	*realloc_after_line(char *memory);
int     check_move(const char *move, int len);
void    treatment_move(char *data, t_stack **a, t_stack **b);
void    exec_instrc(const char *move, t_stack **a, t_stack **b);
void    both_move(void (*move)(t_stack **), t_stack **a, t_stack **b);

#endif