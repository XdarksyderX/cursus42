/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:52:40 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/26 15:52:41 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "../libft/libft.h"
# include "./command_bonus.h"

void	ft_handle_error(char *str);
void	fork_and_exec(int infile_fd, int outfile_fd, t_command command);
int		ft_open(char *filename, int flags);

#endif
