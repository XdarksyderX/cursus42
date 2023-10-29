/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:13:35 by migarci2          #+#    #+#             */
/*   Updated: 2023/10/23 20:13:40 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"
#include <stdlib.h>

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = stack->top;
	stack->top = new_node;
	if (stack->bottom == NULL)
		stack->bottom = new_node;
}

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = tmp;
	stack->bottom = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*second_to_bottom;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	second_to_bottom = stack->top;
	while (second_to_bottom->next != stack->bottom)
		second_to_bottom = second_to_bottom->next;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = second_to_bottom;
	second_to_bottom->next = NULL;
}
