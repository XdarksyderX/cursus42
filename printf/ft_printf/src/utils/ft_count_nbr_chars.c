/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nbr_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:50:50 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/16 16:52:25 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_nbr_chars(long long n)
{
	long long	count;
	int			neg;

	neg = 0;
	count = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	if (neg)
		count++;
	return (count);
}
