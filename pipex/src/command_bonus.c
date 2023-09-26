/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:51:02 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/26 15:51:03 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command_bonus.h"

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

void	ft_exec_command(t_command	command, int infile_fd, int outfile_fd)
{
	dup2(infile_fd, STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	execve(command.pathname, command.argv, command.envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	ft_free_command_list(t_command_list *command_list)
{
	t_command_list	*tmp;

	while (command_list)
	{
		tmp = command_list;
		command_list = command_list->next;
		free(tmp->command.argv);
		free(tmp->command.pathname);
		free(tmp);
	}
	return (0);
}

void	add_command_to_list(t_command_list **command_list, t_command command)
{
	t_command_list	*new_node;
	t_command_list	*tmp;

	new_node = malloc(sizeof(t_command_list));
	if (!new_node)
		ft_handle_error("Malloc error:");
	new_node->command = command;
	new_node->next = NULL;
	if (!*command_list)
		*command_list = new_node;
	else
	{
		tmp = *command_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

t_command_list	*ft_parse_command_list(char **argv, char **envp)
{
	t_command_list	*command_list;
	int				i;

	command_list = NULL;
	i = 2;
	while (argv[i + 1])
	{
		add_command_to_list(&command_list,
			ft_parse_command(argv[i], envp));
		i++;
	}
	return (command_list);
}
