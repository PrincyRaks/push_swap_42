unsigned int	cost_node(t_stack *node_a, t_stack *first_b, int length_a, int length_b)
{
	unsigned int	median_a;
	unsigned int	median_b;
	unsigned int	cost_a;
	unsigned int	cost_b;
	unsigned int	target_index;

	median_a = median(length_a);
	median_b = median(length_b);
	target_index = get_target_index(node_a, first_b);
	cost_a = 0;
	cost_b = 0;
	if (node_a->index <= median_a && target_index <= median_b)
	{
		if (node_a->index >= target_index)
			return (node_a->index + 1);
		return (target_index + 1);
	}
	else if (node_a->index > median_a && target_index > median_b)
	{
		if ((length_a - node_a->index) >= (length_b - target_index))
			return (length_a - node_a->index + 1);
		return (length_b - target_index + 1);
	}
	if (node_a->index < median_a)
		cost_a = node_a->index;
	if (node_a->index >= median_a)
		cost_a = length_a - node_a->index;
	if (target_index < median_b)
		cost_b = target_index;
	if (target_index >= median_b)
		cost_b = length_b - target_index;
	return (cost_a + cost_b + 1);
}

// move not include: pb or pa
void	exec_move(void (*move)(t_stack**), t_stack **data,char *msg, int n)
{
	while (count-- > 0)
	{
		move(data);
		ft_putstr_fd(msg, FD);
	}
}

void	same_move(move, pila a, pile b, count)
{}

void	launch_move_1(t_stack *to_range, t_stack **stack_b, int length_a, int length_b)
{
	unsigned int	median_a;
	unsigned int	median_b;
	unsigned int	index_a;
	unsigned int	target_a;
	unsigned int	move;

	median_a = median(length_a);
	median_b = median(length_b);
	index_a = to_range->index;
	target_a = get_target_index(to_range, *stack_b);
	// r
	if (index_a <= median_a && target_a <= median_b)
	{
		if (index_a >= target_a)
			move = target_a;
		else
			move = index_a;
		while (move-- > 0)
		{
			rotate(stack_a);
			rotate(stack_b);
			ft_putstr_fd("rr", FD);
		}
		if (index_a > target_a)
		{
			move = index_a - target_a;
			while (move-- > 0)
			{
				rotate(stack_a);
				ft_putstr_fd("ra", FD);
			}
		}
		else if (index_a < target_a)
		{
			move = target_a - index_a;
			while (move-- > 0)
			{
				rotate(stack_b);
				ft_putstr_fd("rb", FD);
			}
		}
	}
	// rr
	else if (index_a > median_a && target_a > median_b)
	{
		if ((length_a - index_a) <= (length_b - target_a))
			move = length_a - index_a;
		else
			move = length_b - target_a;
		while (move-- > 0)
		{
			r_rotate(stack_a);
			r_rotate(stack_b);
			ft_putstr_fd("rrr", FD);
		}
		if ((length_a - index_a) < (length_b - target_a))
		{
			move = (length_b - target_a) - (length_a - index_a);
			while (move-- > 0)
			{
				r_rotate(stack_b);
				ft_putstr_fd("rrb", FD);
			}
		}
		if ((length_a - index_a) > (length_b - target_a))
		{
			move = (length_a - index_a) - (length_b - target_a);
			while (move-- > 0)
			{
				r_rotate(stack_a);
				ft_putstr_fd("rra", FD);
			}
		}
	}
	else
	{
		// pile A
		if (index_a <= median_a)
		{
			while (index_a-- > 0)
			{
				rotate(stack_a);
				ft_putstr_fd("ra", FD);
			}
		}
		else if (index_a > median_a)
		{
			index_a = length_a - index_a;
			while (move-- > 0)
			{
				r_rotate(stack_a);
				ft_putstr_fd("rra", FD);
			}
		}
		// PILE B
		if (target_a <= median_b)
		{
			while (target_a-- > 0)
			{
				rotate(stack_b);
				ft_putstr_fd("rb", FD);
			}
		}
		else if (target_a > median_b)
		{
			move = length_b - target_a;
			while (move-- > 0)
			{
				r_rotate(stack_b);
				ft_putstr_fd("rrb", FD);
			}
		}
	}
	push(stack_a, stack_b);
	ft_putstr_fd("pb", FD);
	// insert_target_index(stack_a, stack_b);
}
