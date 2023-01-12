/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:08:36 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/12 19:29:27 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	io_command(int ncmd, t_command *command, char **arg, int *_pipe)
{
	if (command->id == 0)
		command->infile = open_infile(arg[1]);
	else
		command->infile = _pipe[command->id * 2 - 2];
	if (command->id == ncmd - 1)
		command->outfile = open_outfile(arg[ncmd + 2]);
	else
		command->outfile = _pipe[command->id * 2 + 1];
}

void	execute_command(t_command *command, char *path)
{
	if (command->infile == -1 || command->outfile == -1)
		exit(1);
	dup2(command->infile, 0);
	dup2(command->outfile, 1);
	close_fd(3, command->infile, command->outfile, command->outfile + 1);
	execve(whereis_command(command->argument[0], path), command->argument, NULL);
	exit (1);
}

typedef struct s_data
{
	int		id;
	pid_t	pid;
}	t_data;

int	fork_proccess(t_data *data)
{
	int		index;
	pid_t	cpid;

	index = 0;
	while (data[index].id != -1)
	{
		cpid = fork();
		if (cpid == 0)
		{
			if (data[index].id != 0)
				waitpid(data[index - 1].pid, NULL, 0);
			return (index);
		}
		data[index++].pid = cpid;
	}
	waitpid(data[index - 1].pid, NULL, 0);
	exit(1);
}

void	execute_comman(t_data *data)
{
	if (data->id == 0)
		execlp("cat", "cat", "test1", NULL);
	if (data->id == 1)
		execlp("cat", "cat", "test2", NULL);
	else
		execlp("cat", "cat", "test3", NULL);
}

//(int number_argument, char **argument, char **environment_variables)
int	main(void)
{
	int		command_id;
	t_data	data[4];

	data[0].id = 0;
	data[1].id = 1;
	data[2].id = 2;
	data[3].id = -1;
	command_id = fork_proccess(data);
	execute_comman(&data[command_id]);
	return (0);
}
