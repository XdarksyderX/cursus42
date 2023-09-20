/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:38:33 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 16:42:56 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_string_handler(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, STDOUT_FILENO);
	return ((int) ft_strlen((const char *) s));
}
