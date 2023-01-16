/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:58:26 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/13 12:48:22 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_command *cmd, int *pipes, t_files *files, char **env)
{
	cmd->pid = fork();
	if (cmd->pid != IS_CHILD)
		return ;
	if (!cmd->id && files->isheredoc)
		ft_heredoc(pipes, files->limiter);
	io_command(cmd, pipes, files);
	close_pipes(pipes);
	execve(cmd->path, cmd->argument, env);
	clean_all(cmd, files, pipes, YES);
}

void	io_command(t_command *cmd, int *pipes, t_files *files)
{
	int	fd;

	fd = 0;
	if (cmd->id == 0)
	{
		fd = open_infile(files->infile);
		ft_error(fd, cmd);
		if (dup2(fd, 0) == -1 || dup2(pipes[1], 1) == -1)
			exit(1);
	}
	else if (cmd[1].id == -1)
	{
		fd = open_outfile(files->outfile, files->isheredoc);
		ft_error(fd, cmd);
		if (dup2(pipes[cmd->id * 2 - 2], 0) == -1 || dup2(fd, 1) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		ft_error(fd, cmd);
		if (dup2(pipes[cmd->id * 2 - 2], 0) == -1
			|| dup2(pipes[cmd->id * 2 + 1], 1) == -1)
			exit(EXIT_FAILURE);
	}
}

int	wait_allproccess(t_command *command)
{
	int	id;
	int	status;

	id = -1;
	while (command[++id].id != -1)
		waitpid(command[id].pid, &command[id].exit_status, 0);
	status = *((char *)(&command[id - 1].exit_status) + 1);
	return (status);
}
