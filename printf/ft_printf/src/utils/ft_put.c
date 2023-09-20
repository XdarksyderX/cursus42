/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:20:08 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:21:29 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	recursive_putnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nbr >= (unsigned long) base_len)
	{
		recursive_putnbr_base_fd(nbr / base_len, base, fd);
	}
	ft_putchar_fd(base[nbr % base_len], fd);
}

void	ft_puthex_fd(int nbr, int is_upper, int fd)
{
	unsigned int	unbr;
	char			*base;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	unbr = (unsigned int) nbr;
	recursive_putnbr_base_fd(unbr, base, fd);
}

void	ft_putpointer_fd(void *ptr, int fd)
{
	unsigned long long	ptr_value;

	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	ptr_value = (unsigned long) ptr;
	ft_putstr_fd("0x", fd);
	recursive_putnbr_base_fd(ptr_value, "0123456789abcdef", fd);
}

void	ft_putunsigned_fd(unsigned int nb, int fd)
{
	if (nb >= 10)
	{
		ft_putunsigned_fd(nb / 10, fd);
		ft_putunsigned_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}
