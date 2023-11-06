/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:13:35 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:20:14 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = stack->top;
	new_node->prev = NULL;
	if (stack->top)
		stack->top->prev = new_node;
	stack->top = new_node;
	if (!stack->bottom)
		stack->bottom = new_node;
	stack->size++;
}

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->prev = NULL;
	if (tmp->next)
		tmp->next->prev = stack->top;
	tmp->next = stack->top;
	stack->top->prev = tmp;
	stack->top = tmp;
}

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	stack->top->prev = NULL;
}

void	pop(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->top)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	free(tmp);
	stack->size--;
}
