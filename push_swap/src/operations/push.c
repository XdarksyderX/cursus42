/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:13:35 by migarci2          #+#    #+#             */
/*   Updated: 2023/10/23 20:13:40 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b && stack_b->top)
	{
		push(stack_a, stack_b->top->data);
		pop(stack_b);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->top)
	{
		push(stack_b, stack_a->top->data);
		pop(stack_a);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}

