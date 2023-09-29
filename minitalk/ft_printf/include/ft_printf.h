/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:35:13 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:36:07 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>

# include "../libft/libft.h"
# include "./format.h"

int		ft_printf(const char *str, ...);

int		ft_is_space(char c);

int		ft_count_signed(int nbr, int base_len);
int		ft_count_unsigned(int nbr, int base_len);
int		ft_count_pointer(unsigned long unbr);

void	ft_puthex_fd(int nbr, int is_upper, int fd);
void	ft_putpointer_fd(void *ptr, int fd);
void	ft_putunsigned_fd(unsigned int nb, int fd);

double	ft_ceil(double num);

#endif
