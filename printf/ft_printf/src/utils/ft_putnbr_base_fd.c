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

#include "../include/printf.h"

static int	check_base_condition(char *base)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[a] != '\0')
	{
		b = a + 1;
		if (base[a] == '+' || base[a] == '-')
			return (0);
		if (base[a] < ' ' || base[a] > '~')
			return (0);
		while (base[b] != '\0')
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

static void	ft_putmaxneg_base_fd(int nbr, char *base, int fd)
{
	if (nbr <= (-1 * ft_strlen(base)))
	{
		ft_putmaxneg_base(nbr / ft_strlen(base), base, fd);
		ft_putmaxneg_base(nbr % ft_strlen(base), base, fd);
	}
	else
		ft_putchar_fd(base[-nbr], fd);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	if (check_base_condition(base))
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putmaxneg_base_fd(nbr, base, fd);
			return ;
		}
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= ft_strlen(base))
		{
			ft_putnbr_base_fd(nbr / ft_strlen(base), base, fd);
			ft_putnbr_base_fd(nbr % ft_strlen(base), base, fd);
		}
		else
			ft_putchar_fd(base[nbr], fd);
	}
}
