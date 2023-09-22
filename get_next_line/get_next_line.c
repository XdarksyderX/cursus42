/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:54:09 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/20 18:54:10 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **str)
{
	size_t		i;
	char		*tmp;
	char		*line;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (tmp);
	}
	line = ft_substr(*str, 0, i + 1);
	tmp = ft_strdup(&((*str)[i + 1]));
	free(*str);
	*str = tmp;
	return (line);
}

static char	*update_str(char *str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		str = update_str(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (ret <= 0 && (!str || !(*str)))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (extract_line(&str));
}
