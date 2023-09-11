/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:50:17 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/11 18:50:35 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_haystacknhaystack(const char *haystack,
			const char *needle, size_t len)
{
	size_t	j;
	int		i;
	int		not_equal;

	if (*needle == '\0')
		return (haystack);
	while (*haystack != '\0' && j < len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			not_equal = 0;
			while (needle[i] != '\0')
			{
				if (needle[i] != haystack[i])
						not_equal = 1;
				i++;
			}
			if (not_equal == 0)
				return (haystack);
		}
		haystack++;
		j++;
	}
	return (0);
}
