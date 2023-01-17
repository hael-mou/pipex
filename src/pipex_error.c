/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:50:28 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/11 12:51:14 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(const char *s)
{
	ft_putstr_fd("pipex: ", 2);
	perror(s);
}

void	ft_error(int fd, t_command *command)
{
	if (fd == -1)
		exit(EXIT_FAILURE);
	if (!command->path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(command->arg[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	if (!command->isexecutable)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(command->arg[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
}
