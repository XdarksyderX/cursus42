/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:28 by migarci2          #+#    #+#             */
/*   Updated: 2023/10/26 16:52:29 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/stack.h"


int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*input;

	input = ft_parse_args(argc, argv);
	if (!input)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (1);
	}
	stack_a = ft_init_stack('a');
	stack_b = ft_init_stack('b');
	ft_fill_stack(stack_a, input);
	free(input);
	return (0);
}
