/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:35:20 by csil              #+#    #+#             */
/*   Updated: 2023/11/06 12:31:58 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Function that will create the pass through ARGV arguments
	1) Search an access with envp (goal is to find the PATH= line
	2) Create the entire path for the command line
	3) If path have been found return it
	4) Or return NULL if nothing have been found
*/

char	*create_final_path(char **cmds, char **envp)
{
	int		i;
	char	**paths;
	char	*final_path;
	char	*tmp;

	i = 0;
	while (strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(tmp, cmds[0]);
		free(tmp);
		if (access(final_path, F_OK) == 0)
			return (final_path);
		free(final_path);
		i++;
	}
	free_tab(paths);
	return (NULL);
}

/*
	Take the path line created
	If : return == NULL-> perror()
	Else : execute the command line
	through execve()
	If : execve fail-> perror()
*/
void	execute_cmd(char *args, char **envp)
{
	char	**cmds;
	char	*final_path;

	cmds = ft_split(args, ' ');
	final_path = create_final_path(cmds, envp);
	if (!final_path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmds[0], 2);
		ft_putstr_fd("\n", 2);
		free_tab(cmds);
		exit(EXIT_FAILURE);
	}
	if (execve(final_path, cmds, envp) == -1)
	{
		perror(NULL);
		exit (EXIT_FAILURE);
	}
}
