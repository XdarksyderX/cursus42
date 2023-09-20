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

#include "../../include/ft_printf.h"

int	ft_hex_handler(int nb, int is_upper)
{
	ft_puthex_fd(nb, is_upper, STDOUT_FILENO);
	return (ft_count_unsigned(nb, 16));
}
