/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:15:58 by csil              #+#    #+#             */
/*   Updated: 2023/11/06 12:17:50 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wrong_args_number(void)
{
	ft_putstr_fd("Error: wrong numbers of arguments\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;

	if (argc == 5)
	{
		if (pipe(fd) < 0)
			handle_error();
		pid = fork();
		if (pid < 0)
			handle_error();
		else if (pid == 0)
			child_process(argv, envp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			parent_process(argv, envp, fd);
		}
	}
	else
		wrong_args_number();
	close(fd[0]);
	close(fd[1]);
	return (0);
}
