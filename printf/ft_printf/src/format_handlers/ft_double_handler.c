/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:41:17 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:41:31 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	print_integer_part_recursive(long num, int fd)
{
	int count;

	count = 0;
	if (num == 0)
		return (0);
	count += print_integer_part_recursive(num / 10, fd);
	ft_putchar_fd((char)(num % 10 + '0'), fd);
	return (count + 1);
}

int	print_double_recursive(double num, int fd, int precision)
{
	int count;

	count = 0;
	if (precision == 0)
		return (0);
	num *= 10;
	ft_putchar_fd((char)((int)num % 10 + '0'), fd);
	count += print_double_recursive(num - (int)num, fd, precision - 1);
	return (count + 1);
}

int	ft_double_handler(double num)
{
	long	integer_part;
	int		count;

	integer_part = (long)num;
	count = 0;
	if (integer_part == 0)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	else
	{
		count += print_integer_part_recursive(integer_part, 1);
	}
	ft_putchar_fd('.', 1);
	count++;
	count += print_double_recursive(num - integer_part, 1, 6);
	return (count);
}