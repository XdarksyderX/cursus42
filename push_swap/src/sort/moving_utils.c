/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:18:54 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:18:59 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

static void	ft_rotate_both(t_stack *stack_a,
	t_stack *stack_b, t_node *cheapest_node)
{
	while (stack_b->top != cheapest_node->target
		&& stack_a->top != cheapest_node)
		rr(stack_a, stack_b);
	ft_update_indexes(stack_a);
	ft_update_indexes(stack_b);
}

static void	ft_rev_rotate_both(t_stack *stack_a,
	t_stack *stack_b, t_node *cheapest_node)
{
	while (stack_b->top != cheapest_node->target
		&& stack_a->top != cheapest_node)
		rrr(stack_a, stack_b);
	ft_update_indexes(stack_a);
	ft_update_indexes(stack_b);
}

void	ft_prep_to_push(t_stack *stack, t_node *to_push, char id)
{
	while (stack->top != to_push)
	{
		if (id == 'a')
		{
			if (to_push->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (id == 'b')
		{
			if (to_push->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	ft_move_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = ft_get_cheapest(stack_a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target->above_median)
		ft_rev_rotate_both(stack_a, stack_b, cheapest_node);
	ft_prep_to_push(stack_a, cheapest_node, 'a');
	ft_prep_to_push(stack_b, cheapest_node->target, 'b');
	pb(stack_a, stack_b);
}

void	ft_move_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_prep_to_push(stack_a, stack_b->top->target, 'a');
	pa(stack_a, stack_b);
}
