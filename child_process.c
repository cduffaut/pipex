/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:22:52 by csil              #+#    #+#             */
/*   Updated: 2023/11/06 12:46:01 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int fd[])
{
	int		input;

	input = open(argv[1], O_RDONLY);
	if (input < 0)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	dup2(input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(input);
	close(fd[0]);
	close(fd[1]);
	close(input);
	execute_cmd(argv[2], envp);
}
