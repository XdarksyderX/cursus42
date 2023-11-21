/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:12:01 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/11 17:13:02 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = (char *)s;
	while (1)
	{
		if (*str == (char)c)
			tmp = str;
		if (*str == '\0')
		{
			if (c == '\0')
				return (str);
			return (tmp);
		}
		str++;
	}
}
