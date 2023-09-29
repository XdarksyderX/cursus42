/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:53:30 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:14:41 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_int_handler(int n)
{
	ft_putnbr_fd(n, STDOUT_FILENO);
	return (ft_count_signed((long) n, 10));
}
