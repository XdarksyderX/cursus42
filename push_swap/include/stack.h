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
# include <limits.h>
typedef struct node
{
	int			data;
	struct node	*next;
	struct node *prev;
}	t_node;

typedef struct stack
{
	t_node	*top;
	t_node	*bottom;
	int	size;
}	t_stack;

void	push(t_stack *stack, int value);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	pop(t_stack *stack);


int 	*ft_parse_args(int argc, char **argv, int *size);
int 	ft_exists_in_array(int *array, int num, int size);
t_stack	*ft_init_stack();
void	ft_fill_stack(t_stack *stack, int *array, int size);
void	ft_print_stack(t_stack *stack);

int		ft_check_sort(t_stack *stack);
t_node	*ft_find_min_node(t_stack *stack);
t_node	*ft_find_max_node(t_stack *stack);
int		ft_get_median(t_stack *stack);

void	ft_sort_3_elements(t_stack *stack_a);
void	ft_sort_5_elements(t_stack *stack_a, t_stack *stack_b);
void 	push_swap(t_stack *stack_a, t_stack *stack_b);

void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	ft_free_str_nums(char **arr, int size);

#endif
