/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:41 by migarci2          #+#    #+#             */
/*   Updated: 2023/10/26 16:52:42 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_parse_args(int argc, char **argv)
{
	int	*array;
	int	i;

	if (argc < 2)
		return (NULL);
	array = (int *) ft_calloc(argc - 1, sizeof(int));
	if (!array)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i + 1])
			|| !ft_memchr(array, ft_atoi(argv[i + 1]), i))
		{
			ft_putstr_fd("Error\n", STDOUT_FILENO);
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (array);
}

t_stack	*ft_init_stack(char id)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->id = id;
	return (stack);
}

void	ft_fill_stack(t_stack *stack, int *array)
{
	int	i;

	if (!stack || !array)
		return ;
	if (ft_check_sort(array))
		return ;
	i = 0;
	while (i < sizeof(array) / sizeof(int))
	{
		push(stack, array[i]);
		i++;
	}
}
