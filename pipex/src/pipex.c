/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:09:58 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/25 18:10:01 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_handle_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

t_pipex	ft_init_pipex(char **argv, char **envp)
{
	t_pipex	pipex;
	int		pipex_fd[2];

	if (pipe(pipex_fd) == -1)
		ft_handle_error("Pipe error:");
	pipex.infile_fd = open(argv[1], O_RDONLY);
	if (pipex.infile_fd == -1)
		ft_handle_error(argv[1]);
	pipex.outfile_fd = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (pipex.outfile_fd == -1)
		ft_handle_error(argv[4]);
	pipex.pipex_fd[0] = pipex_fd[0];
	pipex.pipex_fd[1] = pipex_fd[1];
	pipex.command1 = ft_parse_command(argv[2], envp);
	pipex.command2 = ft_parse_command(argv[3], envp);
	return (pipex);
}

void	ft_fork_and_exec(t_pipex pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipex.infile_fd, STDIN_FILENO);
		dup2(pipex.pipex_fd[1], STDOUT_FILENO);
		close(pipex.pipex_fd[0]);
		close(pipex.outfile_fd);
		ft_exec_command(pipex.command1);
	}
	else
	{
		close(pipex.pipex_fd[1]);
		close(pipex.infile_fd);
		wait(NULL);
		dup2(pipex.pipex_fd[0], STDIN_FILENO);
		dup2(pipex.outfile_fd, STDOUT_FILENO);
		ft_exec_command(pipex.command2);
	}
}
