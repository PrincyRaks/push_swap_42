#include "push_swap.h"
#include <limits.h>
int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc > 1)
	{
		a = init_data(argv);
		push_swap(&a, &b);
	}
	return (0);
}