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
