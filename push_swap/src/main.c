/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:28 by migarci2          #+#    #+#             */
/*   Updated: 2023/11/06 19:21:05 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*input;
	int		size;

	input = ft_parse_args(argc, argv, &size);
	if (!input)
		ft_error();
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	ft_fill_stack(stack_a, input, size);
	free(input);
	push_swap(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
