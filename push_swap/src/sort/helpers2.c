#include "../../include/stack.h"

static t_node	*ft_find_target_for_node(t_stack *stack_b,
	t_node *current_stack_a)
{
	t_node	*current_stack_b;
	t_node	*target_node;
	long	best_match_index;

	target_node = NULL;
	best_match_index = LONG_MIN;
	current_stack_b = stack_b->top;
	while (current_stack_b)
	{
		if (current_stack_b->data < current_stack_a->data
			&& current_stack_b->data > best_match_index)
		{
			best_match_index = current_stack_b->data;
			target_node = current_stack_b;
		}
		current_stack_b = current_stack_b->next;
	}
	if (best_match_index == LONG_MIN)
		return (ft_find_max_node(stack_b));
	return (target_node);
}

void	ft_set_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_stack_a;

	current_stack_a = stack_a->top;
	while (current_stack_a)
	{
		current_stack_a->target = ft_find_target_for_node(stack_b,
				current_stack_a);
		current_stack_a = current_stack_a->next;
	}
}

void	ft_set_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_stack_a;
	int		cost;

	current_stack_a = stack_a->top;
	while (current_stack_a)
	{
		current_stack_a->cost = current_stack_a->index;
		if (!current_stack_a->above_median)
			current_stack_a->cost += stack_a->size - current_stack_a->index;
		if (current_stack_a->cost > stack_a->size)
			current_stack_a->cost -= current_stack_a->target->index;
		else
			current_stack_a->cost += stack_b->size
				- current_stack_a->target->index;
		current_stack_a = current_stack_a->next;
	}
}

void	ft_set_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->cheapest = true;
}

t_node	*ft_get_cheapest(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_set_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_update_indexes(stack_a);
	ft_update_indexes(stack_b);
	ft_set_targets(stack_a, stack_b);
	ft_set_costs(stack_a, stack_b);
	ft_set_cheapest(stack_a);
}

