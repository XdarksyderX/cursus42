/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:49:49 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/26 15:49:50 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../includes/command_bonus.h"

void	ft_handle_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	fork_and_exec(int infile_fd, int outfile_fd, t_command command)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ft_exec_command(command, infile_fd, outfile_fd);
	else if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

int	ft_open(char *filename, int flags)
{
	int	fd;

	fd = open(filename, flags);
	if (fd == -1)
		ft_handle_error(filename);
	return (fd);
}
