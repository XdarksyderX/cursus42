/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:57:43 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/15 20:57:43 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_lstmap_args {
	t_list	**new;
	t_list	**p;
	void	*(*f)(void *);
	void	(*del)(void *);
}	t_lstmap_args;

static t_list	*ft_lstmap_aux(t_list *lst, t_lstmap_args *args)
{
	void	*new_content;

	while (lst)
	{
		new_content = args->f(lst->content);
		if (!new_content)
		{
			ft_lstclear(args->new, args->del);
			return (NULL);
		}
		(*args->p)->next = ft_lstnew(new_content);
		if (!(*args->p)->next)
		{
			args->del(new_content);
			ft_lstclear(args->new, args->del);
			return (NULL);
		}
		*args->p = (*args->p)->next;
		lst = lst->next;
	}
	return (*args->new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*new;
	t_list			*p;
	void			*new_content;
	t_lstmap_args	args;

	if (!lst)
		return (NULL);
	new_content = f(lst->content);
	if (!new_content)
		return (NULL);
	new = ft_lstnew(new_content);
	if (!new)
	{
		del(new_content);
		return (NULL);
	}
	p = new;
	args = (t_lstmap_args){&new, &p, f, del};
	lst = lst->next;
	return (ft_lstmap_aux(lst, &args));
}
