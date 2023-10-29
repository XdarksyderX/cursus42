/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:13:35 by migarci2          #+#    #+#             */
/*   Updated: 2023/10/23 20:13:40 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

