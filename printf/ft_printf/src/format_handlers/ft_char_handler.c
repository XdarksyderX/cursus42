/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:34:29 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 16:34:35 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_char_handler(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
