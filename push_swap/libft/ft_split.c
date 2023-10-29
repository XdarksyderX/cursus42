/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:14:23 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/14 19:14:24 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_and_fill(char const *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free_memory(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	*ft_aux_split(char const *s, char c, char **str, int *j)
{
	int	i;
	int	start;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[*j] = ft_alloc_and_fill(s, start, i);
			if (!(str[*j]))
			{
				ft_free_memory(str, *j);
				return (NULL);
			}
			(*j)++;
		}
		else
			i++;
	}
	return (str);
}

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;

	j = 0;
	str = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!str)
		return (NULL);
	if (!ft_aux_split(s, c, str, &j))
		return (NULL);
	str[j] = NULL;
	return (str);
}
