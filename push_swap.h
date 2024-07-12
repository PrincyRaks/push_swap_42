/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:44:45 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/12 16:31:08 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*top;
	struct s_stack	*bottom;
	struct s_stack	*next;
}					t_stack;
void				print_error(void);
long				*check_input(char **argv);
void				swap(t_stack *node);

int					strlen_tab(char **str);
char				*ft_strjoin_data(char *s1, char *s2);
long				*convert_int(char *str);
int					not_dup(long *number);
int					check_number(char *s);

t_stack				*init_stack(long *tab_num);
t_stack				*create_node(int number, int index);
void				ft_lstadd_back(t_stack **lst, t_stack *new);

#endif