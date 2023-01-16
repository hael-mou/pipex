/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:07:10 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/13 20:18:53 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_files	*getfiles(char **argument, int number_argument)
{
	t_files	*files;

	files = malloc(sizeof(t_files));
	if (!files)
		exit(EXIT_FAILURE);
	files->isheredoc = 0;
	if (isheredoc(argument))
	{
		files->isheredoc = 1;
		files->limiter = argument[2];
	}
	else
		files->infile = argument[1];
	files->outfile = argument[number_argument - 1];
	return (files);
}

int	*create_pipes(int number_command)
{
	int	*_pipe;
	int	n_pipe;
	int	i;

	i = 0;
	n_pipe = number_command * 2 - 1;
	_pipe = malloc(n_pipe * sizeof(int));
	if (!_pipe)
		return (NULL);
	while (--number_command)
	{
		if (pipe(_pipe + i) == PIPE_ERROR)
		{
			free(_pipe);
			exit(EXIT_FAILURE);
		}
		i += 2;
	}
	_pipe[n_pipe -1] = -1;
	return (_pipe);
}

void	close_pipes(int	*pipes)
{
	while (*pipes != -1)
		close(*pipes++);
}

int	open_infile(char *infile)
{
	int	fd;

	if (access(infile, F_OK | R_OK) == NO_PERMISSION)
		ft_perror(infile);
	fd = open(infile, O_RDONLY);
	return (fd);
}

int	open_outfile(char *outfile, int isheredoc)
{
	int	fd;

	if (access(outfile, F_OK) != FILE_NOT_FOUND)
		if (access(outfile, W_OK) == NO_PERMISSION)
			ft_perror(outfile);
	if (isheredoc)
		fd = open(outfile, O_RDWR | O_CREAT | O_APPEND, 0666);
	else
		fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	return (fd);
}
