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


static void recursive_putnbr_base_fd(unsigned int nbr, char *base, int fd)
{
    int base_len = ft_strlen(base);

    if (nbr >= (unsigned int)base_len)
    {
        recursive_putnbr_base_fd(nbr / base_len, base, fd);
    }
    ft_putchar_fd(base[nbr % base_len], fd);
}

void ft_putnbr_base_fd(int nbr, char *base, int fd)
{
    unsigned int unbr;

    if (ft_strlen(base) == 16 && nbr < 0)
    {
        unbr = (unsigned int)nbr;
    }
    else
    {
        if (nbr < 0)
        {
            unbr = (unsigned int)(-nbr);
            ft_putchar_fd('-', fd);
        }
        else
        {
            unbr = (unsigned int)nbr;
        }
    }
    recursive_putnbr_base_fd(unbr, base, fd);
}
