/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:09:52 by migarci2          #+#    #+#             */
/*   Updated: 2023/09/25 18:09:53 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", STDERR_FILENO);
		return (1);
	}
	pipex = ft_init_pipex(argv, envp);
	ft_fork_and_exec(pipex);
	return (0);
}
