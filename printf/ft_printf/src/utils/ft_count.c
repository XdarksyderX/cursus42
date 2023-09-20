/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nbr_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:50:50 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 16:52:25 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_count_signed(int nbr, int base_len)
{
	int	count;
	int	neg;

	neg = 0;
	count = 0;
	if (nbr == INT_MIN)
		return (11);
	if (nbr < 0)
	{
		nbr = -nbr;
		neg = 1;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_len;
		count++;
	}
	if (neg)
		count++;
	return (count);
}

int	ft_count_unsigned(int nbr, int base_len)
{
	unsigned int	unbr;
	unsigned int	count;

	unbr = (unsigned int) nbr;
	if (unbr == 0)
		return (1);
	count = 0;
	while (unbr > 0)
	{
		unbr /= base_len;
		count++;
	}
	return (count);
}

int	ft_count_pointer(unsigned long unbr)
{
	unsigned int	count;

	if (unbr == 0)
		return (1);
	count = 0;
	while (unbr > 0)
	{
		unbr /= 16;
		count++;
	}
	return (count + 2);
}
