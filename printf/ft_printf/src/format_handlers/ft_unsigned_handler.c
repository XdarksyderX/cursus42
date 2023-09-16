/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:11:15 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:14:30 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

void	ft_putun_fd(unsigned int nb, int fd)
{
	if (nb >= 10)
	{
		ft_putun_fd(nb / 10, fd);
		ft_putun_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}

int	ft_unsigned_handler(unsigned int n)
{
	ft_putun_fd(n, 1);
	return (ft_count_nbr_chars((long long) n));
}
