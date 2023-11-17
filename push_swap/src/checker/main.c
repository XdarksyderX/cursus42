#include "../../include/stack.h"

void	ft_parse_instruction(char *inst, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(inst, "sa", 2) && ft_strlen(inst) == 2)
		sa(stack_a);
	else if (!ft_strncmp(inst, "sb", 2) && ft_strlen(inst) == 2)
		sb(stack_b);
	else if (!ft_strncmp(inst, "ss", 2) && ft_strlen(inst) == 2)
		ss(stack_a, stack_b);
	else if (!ft_strncmp(inst, "pa", 2) && ft_strlen(inst) == 2)
		pa(stack_a, stack_b);
	else if (!ft_strncmp(inst, "pb", 2) && ft_strlen(inst) == 2)
		pb(stack_a, stack_b);
	else if (!ft_strncmp(inst, "ra", 2) && ft_strlen(inst) == 2)
		ra(stack_a);
	else if (!ft_strncmp(inst, "rb", 2) && ft_strlen(inst) == 2)
		rb(stack_b);
	else if (!ft_strncmp(inst, "rr", 2) && ft_strlen(inst) == 2)
		rr(stack_a, stack_b);
	else if (!ft_strncmp(inst, "rra", 3) && ft_strlen(inst) == 3)
		rra(stack_a);
	else if (!ft_strncmp(inst, "rrb", 3) && ft_strlen(inst) == 3)
		rrb(stack_b);
	else if (!ft_strncmp(inst, "rrr", 3) && ft_strlen(inst) == 3)
		rrr(stack_a, stack_b);
	else
		ft_error();
}


void	ft_check(t_stack *stack_a, t_stack *stack_b)
{
	char	*inst;

	inst = get_next_line(STDIN_FILENO);
	while (inst)
	{
		ft_parse_instruction(inst, stack_a, stack_b);
		free(inst);
		inst = get_next_line(STDIN_FILENO);
	}
	if (inst)
		free(inst);
	if (ft_check_sort(stack_a) && stack_b->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*input;
	int		size;

	input = ft_parse_args(argc, argv, &size);
	if (!input)
		ft_error();
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	ft_fill_stack(stack_a, input, size);
	free(input);
	ft_check(stack_a, stack_b);
	return (0);
}
