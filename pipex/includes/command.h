/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:10:19 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/25 18:10:20 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "pipex.h"

typedef struct s_command {
	char	*pathname;
	char	**argv;
	char	**envp;
}	t_command;

t_command	ft_parse_command(char	*str, char **envp);
void		ft_exec_command(t_command	command);

#endif
