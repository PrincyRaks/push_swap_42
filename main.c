#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack **b;
	// t_stack *pile_a;
	// t_stack *pile_b;
	// int i;

	if (argc > 1)
	{
		// i = 2;
		a = init_data(argv);
		// printf("sort ve : %d \n", sortable(a));
		b = (t_stack **)malloc(sizeof(t_stack *));
		push_swap(&a, b);
		// pile_a = a;
		// pile_b = *b;
		// printf("PILE de A: \n");
		// while (a)
		// {
		// 	printf("value: %d |index: %d | next: %p | top: %p | bottom: %p\n",
		// 		a->value, a->index, a->next, a->top, a->bottom);
		// 	a = a->next;
		// }
		// printf("PILE de B: \n");
		// while (*b)
		// {
		// 	printf("value: %d |index: %d  | next: %p | top: %p | bottom: %p\n",
		// 		(*b)->value, (*b)->index, (*b)->next, (*b)->top, (*b)->bottom);
		// 	*b = (*b)->next;
		// }
		// printf("TEST MOVE \n");
		// push_swap(&pile_a, &pile_b);
		// printf("PILE de A:\n");
		// while (pile_a)
		// {
		// 	printf("value: %d |index: %d | next: %p | top: %p | bottom: %p\n", 
		// 		pile_a->value, pile_a->index,
		// 		pile_a->next, pile_a->top, 
		// 		pile_a->bottom);
		// 	pile_a = pile_a->next;
		// }
		// printf("\nPILE de B: \n");
		// while (pile_b)
		// {
		// 	printf("value: %d | index: %d | next: %p | top: %p | bottom: %p \n",
		// 		pile_b->value, pile_b->index, pile_b->next, pile_b->top,
		// 		pile_b->bottom);
		// 	pile_b = pile_b->next;
		// }
	}
	return (0);
}