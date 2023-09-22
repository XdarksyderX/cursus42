/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:53:57 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/20 18:54:00 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_FileBufferNode	*get_fd_node(t_FileBufferNode **head, int fd)
{
	t_FileBufferNode	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_FileBufferNode));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->buffer = ft_strdup("");
	if (!tmp->buffer)
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_FileBufferNode	*head;
	t_FileBufferNode		*node;
	char					buffer[BUFFER_SIZE + 1];
	int						ret;

	node = get_fd_node(&head, fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || !node)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		node->buffer = update_str(node->buffer, buffer);
		if (ft_strchr(node->buffer, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (ret <= 0 && (!node->buffer || !*(node->buffer)))
	{
		free(node->buffer);
		node->buffer = NULL;
		return (NULL);
	}
	return (extract_line(&(node->buffer)));
}
