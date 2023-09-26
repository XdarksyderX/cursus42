/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:50:53 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/26 15:50:54 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_command_list	*command_list;
	int				pipefd[2];
	int				infile_fd;
	int				outfile_fd;

	infile_fd = ft_open(argv[1], O_RDONLY);
	command_list = ft_parse_command_list(argv, envp);
	while (command_list && command_list->next)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		fork_and_exec(infile_fd, pipefd[1], command_list->command);
		close(pipefd[1]);
		infile_fd = pipefd[0];
		command_list = command_list->next;
	}
	outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (outfile_fd == -1)
		ft_handle_error(argv[argc - 1]);
	fork_and_exec(infile_fd, outfile_fd, command_list->command);
	wait(NULL);
	return (ft_free_command_list(command_list));
}
