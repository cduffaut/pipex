/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:28:06 by csil              #+#    #+#             */
/*   Updated: 2023/11/06 12:38:06 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **argv, char **envp, int fd[])
{
	int		output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output < 0)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(argv[4], 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(output);
	execute_cmd(argv[3], envp);
}
