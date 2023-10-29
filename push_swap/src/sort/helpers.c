#include "../../include/stack.h"

void	ft_print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
	{
		ft_putstr_fd("Stack is empty.\n", STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd("Stack: ", STDOUT_FILENO);
	current = stack->top;
	while (1)
	{
		ft_putnbr_fd(current->data, STDOUT_FILENO);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

t_node	*ft_find_min_node(t_stack *stack)
{
	int		min;
	t_node	*min_node;
	t_node	*temp_node;

	if (!stack || !stack->top)
		return (NULL);
	min = stack->top->data;
	min_node = stack->top;
	temp_node = stack->top;
	while (temp_node)
	{
		if (temp_node->data < min)
		{
			min = temp_node->data;
			min_node = temp_node;
		}
		temp_node = temp_node->next;
	}
	return (min_node);
}

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

int	ft_get_median(t_stack *stack)
{
	int	*array;
	int	i;
	int	j;
	int	tmp;

	array = (int *) malloc(sizeof(int) * stack->size);
	if (!array)
		return (-1);
	i = 0;
	while (stack->top)
	{
		array[i] = stack->top->data;
		stack->top = stack->top->next;
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array[stack->size / 2]);
}