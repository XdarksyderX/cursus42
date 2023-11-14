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

void	ft_set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*nodes[3];
	long	best_match_index;

	nodes[0] = stack_a->top;
	while (nodes[0])
	{
		best_match_index = LONG_MIN;
		nodes[1] = stack_b->top;
		nodes[2] = NULL;
		while (nodes[1])
		{
			if (nodes[1]->data < nodes[0]->data
				&& nodes[1]->data > best_match_index)
			{
				best_match_index = nodes[1]->data;
				nodes[2] = nodes[1];
			}
			nodes[1] = nodes[1]->next;
		}
		if (best_match_index == LONG_MIN)
			nodes[0]->target = ft_find_max_node(stack_b);
		else
			nodes[0]->target = nodes[2];
		nodes[0] = nodes[0]->next;
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
	t_node	*cheapest_node;
	t_node	*current;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	cheapest_node = ft_get_cheapest(stack);
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
