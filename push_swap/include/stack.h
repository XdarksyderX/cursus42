/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <migarci2@student.42malaga.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:45 by xdarksyderx       #+#    #+#             */
/*   Updated: 2023/10/26 16:53:46 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libft/libft.h"

typedef struct node
{
	int			data;
	struct node	*next;
}	t_node;

typedef struct stack
{
	t_node	*top;
	t_node	*bottom;
	char	id;
}	t_stack;

int		*ft_parse_args(int argc, char **argv);
t_stack	*ft_init_stack(char id);
void	ft_fill_stack(t_stack *stack, int *array);

int		ft_check_sort(int *array);

#endif
