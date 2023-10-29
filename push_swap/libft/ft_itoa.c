/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:44:16 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/14 19:44:17 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		aux = str[j];
		str[j] = str[i];
		str[i] = aux;
		i++;
		j--;
	}
	return (str);
}

static void	ft_fill(int n, char *result, int i, int neg)
{
	if (n == 0)
		result[i++] = '0';
	while (n > 0)
	{
		result[i++] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		result[i++] = '-';
	result[i] = '\0';
}

int	ft_count(int n, int neg)
{
	int	count;

	count = 0;
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

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	result = (char *) malloc(sizeof(char) * (ft_count(n, neg) + 1));
	if (!result)
		return (NULL);
	ft_fill(n, result, i, neg);
	return (ft_strrev(result));
}
