/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:36:36 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 16:53:14 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		bytes_written;
	int		i;

	va_start(var_args, str);
	i = 0;
	bytes_written = 0;
	while (str[i])
	{
		if (str[i] == '%' && !ft_is_space(str[i + 1]))
		{
			bytes_written += ft_format(str[i + 1], var_args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			if (ft_isprint(str[i]))
				bytes_written++;
		}
		i++;
	}
	return (bytes_written);
}
