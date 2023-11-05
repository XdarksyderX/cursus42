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

static int	*allocate_and_fill_array(char **str_nums, int *size)
{
	int	i;
	int	*array;

	i = 0;
	while (str_nums[i])
		i++;
	*size = i;
	array = (int *)ft_calloc(i, sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (str_nums[i])
	{
		if (!is_numeric(str_nums[i]) || !ft_exists_in_array(array, ft_atoi(str_nums[i]), i))
		{
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi(str_nums[i]);
		i++;
	}
	return (array);
}

int	*ft_parse_args(int argc, char **argv, int *size)
{
	char	**str_nums = NULL;
	int		*array = NULL;

	if (argc < 2 || !argv[argc - 1][0])
		return (NULL);

	if (argc == 2)
	{
		str_nums = ft_split(argv[1], ' ');
		if (str_nums)
		{
			array = allocate_and_fill_array(str_nums, size);
			ft_free_str_nums(str_nums, *size);
		}
	}
	else if (argc > 2)
	{
		str_nums = argv + 1;
		array = allocate_and_fill_array(str_nums, size);
	}
	if (!str_nums || !array)
		return (NULL);
	return (array);
}

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

void	ft_fill_stack(t_stack *stack, int *array, int size)
{
	int	i;

	if (!stack || !array)
		return ;
	i = size - 1;
	while (i >= 0)
	{
		push(stack, array[i]);
		i--;
	}
	stack->size = size;
}
