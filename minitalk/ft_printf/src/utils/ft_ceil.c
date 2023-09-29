/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:35:52 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 17:35:54 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_ceil(double num)
{
	int		integer_part;
	double	fractional_part;

	integer_part = (int)num;
	fractional_part = num - (double)integer_part;
	if (fractional_part > 0)
		return ((double)(integer_part + 1));
	else
		return ((double)integer_part);
}
