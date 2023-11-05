#include "../../include/stack.h"

t_node	*ft_find_max_node(t_stack *stack)
{
	int				highest;
	t_node			*highest_node;
	t_node			*temp_node;

	if (NULL == stack || stack->top == NULL)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL;
	temp_node = stack->top;
	while (temp_node)
	{
		if (temp_node->data > highest)
		{
			highest = temp_node->data;
			highest_node = temp_node;
		}
		temp_node = temp_node->next;
	}
	return (highest_node);
}

int	ft_check_sort(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (0);

	current = stack->top;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_update_indexes(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*current;

	i = 0;
	if (!stack)
		return ;
	median = stack->size / 2;
	current = stack->top;
	while (stack->size)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

void	ft_move_a_to_b(t_stack	*stack_a, t_stack *stack_b)
{
	t_node	*current;

	if (!stack_a || !stack_b)
		return ;
	current = stack_a->top;
	while (current && !current->cheapest)
		current = current->next;
	if (current->above_median)
	{
		while (stack_a->top != current)
			ra(stack_a);
	}
	else
	{
		while (stack_a->top != current)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

