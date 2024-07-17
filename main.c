/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:31:05 by rrakotos          #+#    #+#             */
/*   Updated: 2024/07/12 16:57:53 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack **b;
	t_stack *pile_a;
	t_stack **pile_b;

	a = NULL;
	if (argc > 1)
	{
		a = init_data(argv);
		// b = (t_stack**)malloc(sizeof(t_stack*));
		// printf("b: %p et *b: %p\n",b ,*b);
		// pile_a = a;
		// pile_b = b;
		// test function move
		// push_swap(a, b);
		// printf("PILE de A\n");
		// while (a)
		// {
		// 	printf("value: %d | next: %p | top: %p | bottom: %p\n",
		// 	a->value, a->next, a->top, a->bottom);
		// 	a = a->next;
		// }
		// printf("PILE de B\n");
		// while (*b)
		// {
		// 	printf("value: %d | next: %p | top: %p | bottom: %p\n",
		// 	(*b)->value, (*b)->next, (*b)->top, (*b)->bottom);
		// 	*b = (*b)->next;
		// }
		// push(&pile_a, pile_b);
		// printf("PUSH !!! :\n");
		// printf("PILE de A \n");
		// while (pile_a)
		// {
		// 	printf("value: %d | next: %p | top: %p | bottom: %p\n",
		// 	pile_a->value, pile_a->next, pile_a->top, pile_a->bottom);
		// 	pile_a = pile_a->next;
		// }
		// printf("PILE de B: \n");
		// while (*pile_b)
		// {
		// 	printf("value: %d | next: %p | top: %p | bottom: %p\n",
		// 	(*pile_b)->value, (*pile_b)->next, (*pile_b)->top, (*pile_b)->bottom);
		// 	*pile_b = (*pile_b)->next;
		// }
	}
	return (0);
}