/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:10:13 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/25 18:10:14 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "../libft/libft.h"
# include "command.h"

typedef struct s_pipex {
	int			pipex_fd[2];
	int			infile_fd;
	int			outfile_fd;
	t_command	command1;
	t_command	command2;
}	t_pipex;

void	ft_handle_error(char *str);
t_pipex	ft_init_pipex(char **argv, char **envp);
void	ft_fork_and_exec(t_pipex pipex);

#endif
