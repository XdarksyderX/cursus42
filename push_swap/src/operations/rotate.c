/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:14:26 by migarci2          #+#    #+#             */
/*   Updated: 2023/10/23 20:14:27 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}