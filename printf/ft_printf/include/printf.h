/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:35:13 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:36:07 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include "format.h"

int		ft_is_space(char c);
int		ft_count_nbr_chars(long long n);
void	ft_putnbr_base_fd(int nbr, char *base, int fd);
double	ft_ceil(double num);

#endif
