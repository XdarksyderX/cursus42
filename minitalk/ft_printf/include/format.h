/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:22:56 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 16:34:44 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include <stdarg.h>

int	ft_format(char code, va_list var_args);
int	ft_char_handler(char c);
int	ft_string_handler(char *str);
int	ft_pointer_handler(void *ptr);
int	ft_int_handler(int n);
int	ft_unsigned_handler(unsigned int n);
int	ft_hex_handler(int nb, int is_upper);

#endif
