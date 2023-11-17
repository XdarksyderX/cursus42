/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:18:54 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:18:59 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"


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
	while (current)
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

void	ft_set_stack(t_stack *stack_a, t_stack *stack_b, char id)
{
	ft_update_indexes(stack_a);
	ft_update_indexes(stack_b);
	if (id == 'a')
	{
		ft_set_targets_a(stack_a, stack_b);
		ft_set_costs(stack_a, stack_b);
		ft_set_cheapest(stack_a);
	}
	else if (id == 'b')
	{
		ft_set_targets_b(stack_a, stack_b);
		ft_set_costs(stack_b, stack_a);
		ft_set_cheapest(stack_b);
	}
}

void	ft_set_targets_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*nodes[3];
	long	best_match_index;

	nodes[0] = stack_b->top;
	while (nodes[0])
	{
		best_match_index = LONG_MAX;
		nodes[1] = stack_a->top;
		nodes[2] = NULL;
		while (nodes[1])
		{
			if (nodes[1]->data > nodes[0]->data
				&& nodes[1]->data < best_match_index)
			{
				best_match_index = nodes[1]->data;
				nodes[2] = nodes[1];
			}
			nodes[1] = nodes[1]->next;
		}
		if (best_match_index == LONG_MAX)
			nodes[0]->target = ft_find_min_node(stack_a);
		else
			nodes[0]->target = nodes[2];
		nodes[0] = nodes[0]->next;
	}
}
