/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:09:45 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/25 18:09:47 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_command	ft_parse_command(char	*str, char **envp)
{
	t_command	command;
	char		**argv;
	char		*pathname;

	argv = ft_split(str, ' ');
	pathname = ft_strjoin("/bin/", argv[0]);
	command = (t_command){pathname, argv, envp};
	return (command);
}

void	ft_exec_command(t_command	command)
{
	execve(command.pathname, command.argv, command.envp);
	perror(ft_strjoin("Error: ", command.argv[0]));
	exit(EXIT_FAILURE);
}
