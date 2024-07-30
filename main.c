#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc > 1)
	{
		a = init_data(argv);
		b = NULL;
		push_swap(&a, &b);
		free_list(&a);
		free_list(&b);
	}
	return (0);
}