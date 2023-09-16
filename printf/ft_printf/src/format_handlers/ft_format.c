/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:23:23 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:04:57 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/format.h"
#include "../../include/printf.h"

int	ft_format(char code, va_list var_args )
{
	if (code == 'c' || code == '%')
		return (ft_char_handler(va_arg(var_args, char)));
	else if (code == 's')
		return (ft_string_handler(va_arg(var_args, char *)));
	else if (code == 'p')
		return (ft_pointer_handler(va_arg(var_args, void *)));
	else if (code == 'd')
		return (ft_double_handler(va_arg(var_args, double)));
	else if (code == 'i')
		return (ft_int_handler(va_arg(var_args, int)));
	else if (code == 'u')
		return (ft_unsigned_handler(va_arg(var_args, unsigned int)));
	else if (code == 'X')
		return (ft_hex_handler(va_arg(var_args, int), 1));
	else if (code == 'x')
		return (ft_hex_handler(va_arg(var_args, int), 0));
}
