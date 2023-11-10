/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:18:54 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:18:59 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_node	*current_a;

	current_a = stack_a->top;
	while (current_a)
	{
		current_a->cost = current_a->index;
		if (!current_a->above_median)
			current_a->cost = stack_a->size - current_a->index;
		if (current_a->target)
		{
			if (current_a->target->above_median)
				current_a->cost += current_a->target->index;
			else
				current_a->cost += stack_b->size - current_a->target->index;
		}
		else
			current_a->cost = INT_MAX;
		current_a = current_a->next;
	}
}

void	ft_set_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest_node;
	long	cheapest_value;

	if (!stack || !stack->top)
		return ;
	cheapest_value = LONG_MAX;
	current = stack->top;
	while (current)
	{
		current->cheapest = false;
		if (current->cost < cheapest_value)
		{
			cheapest_value = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node != NULL)
		cheapest_node->cheapest = true;
}

t_node	*ft_get_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest_node;
	long	cheapest_cost;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	cheapest_node = current;
	cheapest_cost = current->cost;
	while (current)
	{
		if (current->cost < cheapest_cost)
		{
			cheapest_cost = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

