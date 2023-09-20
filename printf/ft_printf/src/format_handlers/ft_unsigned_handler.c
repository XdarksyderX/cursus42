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

#include "../../include/ft_printf.h"

int	ft_unsigned_handler(unsigned int n)
{
	ft_putunsigned_fd(n, STDOUT_FILENO);
	return (ft_count_unsigned((int) n, 10));
}
