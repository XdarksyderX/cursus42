/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:34:01 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:38:29 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

int	ft_hex_handler(int nb, int is_upper)
{
	char	*base;
	int		digits;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ft_putnbr_base_fd(nb, base, 1);
	digits = (int) ft_ceil(ft_count_nbr_chars((long long) nb) / 1.2041);
	return (digits);
}
