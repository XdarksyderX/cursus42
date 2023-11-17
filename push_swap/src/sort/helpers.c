/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:19:52 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:19:53 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_node	*ft_find_min_node(t_stack *stack)
{
	int				lowest;
	t_node			*lowest_node;
	t_node			*temp_node;

	if (NULL == stack || stack->top == NULL)
		return (NULL);
	lowest = INT_MAX;
	lowest_node = NULL;
	temp_node = stack->top;
	while (temp_node)
	{
		if (temp_node->data < lowest)
		{
			lowest = temp_node->data;
			lowest_node = temp_node;
		}
		temp_node = temp_node->next;
	}
	return (lowest_node);
}
