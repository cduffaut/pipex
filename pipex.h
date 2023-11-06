/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:31:10 by csil              #+#    #+#             */
/*   Updated: 2023/11/06 12:50:15 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <stdio.h>
# include <fcntl.h>

# include <sys/types.h>
# include <sys/wait.h>

// Process
void	child_process(char **argv, char **envp, int fd[]);
void	parent_process(char **argv, char **envp, int fd[]);

// Error gestion
void	handle_error(void);
void	free_tab(char **tab);
void	wrong_args_number(void);

// Path creation
void	execute_cmd(char *args, char **envp);
char	*create_final_path(char **cmds, char **envp);

#endif
