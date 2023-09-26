/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:52:14 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/26 15:52:15 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_BONUS_H
# define COMMAND_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef struct s_command {
	char	*pathname;
	char	**argv;
	char	**envp;
}	t_command;

typedef struct s_command_list {
	t_command				command;
	struct s_command_list	*next;
}	t_command_list;

t_command		ft_parse_command(char	*str, char **envp);
int				ft_free_command_list(t_command_list *command_list);
t_command_list	*ft_parse_command_list(char **argv, char **envp);
void			ft_exec_command(t_command	command, int infile_fd,
					int outfile_fd);

void			ft_handle_error(char *str);

#endif
