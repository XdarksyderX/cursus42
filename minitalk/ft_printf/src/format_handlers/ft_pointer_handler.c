/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:11:05 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/20 16:11:06 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_pointer_handler(void *ptr)
{
	ft_putpointer_fd(ptr, STDOUT_FILENO);
	if (!ptr)
		return (ft_strlen("(nil)"));
	return (ft_count_pointer((unsigned long) ptr));
}
