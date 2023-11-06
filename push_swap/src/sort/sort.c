/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:23 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:19:45 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void	ft_sort_3_elements(t_stack *stack_a)
{
	t_node	*highest_node;

	if (stack_a == NULL || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->top->data > stack_a->top->next->data)
			sa(stack_a);
		return ;
	}
	highest_node = ft_find_max_node(stack_a);
	if (stack_a->top == highest_node)
		ra(stack_a);
	else if (stack_a->top->next == highest_node)
		rra(stack_a);
	if (stack_a->top->data > stack_a->top->next->data)
		sa(stack_a);
}

void	ft_sort_5_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;

	min_node = ft_find_min_node(stack_a);
	while (stack_a->top != min_node)
	{
		if (stack_a->top->data == min_node->data)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	min_node = ft_find_min_node(stack_a);
	while (stack_a->top != min_node)
	{
		if (stack_a->top->data == min_node->data)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_sort_3_elements(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;

	size_a = stack_a->size;
	if (size_a-- > 3 && !ft_check_sort(stack_a))
		pb(stack_a, stack_b);
	if (size_a-- > 3 && !ft_check_sort(stack_a))
		pb(stack_a, stack_b);
	while (size_a-- > 3 && !ft_check_sort(stack_a))
	{
		ft_set_stack(stack_a, stack_b);
		ft_move_a_b(stack_a, stack_b);
	}
	ft_sort_3_elements(stack_a);
	while (stack_b->size)
	{
		ft_set_stack(stack_b, stack_a);
		ft_move_b_a(stack_a, stack_b);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (ft_check_sort(stack_a))
		return ;
	else if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort_3_elements(stack_a);
	else if (size <= 5)
		ft_sort_5_elements(stack_a, stack_b);
	else
		ft_insort(stack_a, stack_b);
}
