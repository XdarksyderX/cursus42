/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:50:17 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/11 19:26:51 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack,
			const char *needle, size_t len)
{
	size_t	j;
	int		i;
	int		not_equal;

	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && j < len)
	{
		if (*haystack == *needle)
		{
			i = -1;
			not_equal = 0;
			while (needle[++i] != '\0')
			{
				if (needle[i] != haystack[i])
						not_equal = 1;
			}
			if (not_equal == 0)
				return ((char *)haystack);
		}
		haystack++;
		j++;
	}
	return (0);
}
