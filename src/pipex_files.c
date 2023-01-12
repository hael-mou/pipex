/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:07:10 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/11 13:04:50 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *infile)
{
	int	fd;

	if (access(infile, F_OK | R_OK) == NO_PERMISSION)
		ft_perror(infile);
	fd = open(infile, O_RDONLY);
	return (fd);
}

int	open_outfile(char *outfile)
{
	int	fd;

	if (access(outfile, F_OK) != FILE_NOT_FOUND)
		if (access(outfile, W_OK) == NO_PERMISSION)
			ft_perror(outfile);
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	return (fd);
}

int	*create_pipes(int number_command)
{
	int	*_pipe;
	int	i;

	i = 0;
	_pipe = malloc((number_command - 1) * 2 * sizeof(int));
	if (!_pipe)
		return (NULL);
	while (--number_command)
	{
		if (pipe(_pipe + i) == PIPE_ERROR)
		{
			_pipe[i] = -1;
			_pipe[i + 1] = -1;
		}
		i += 2;
	}
	return (_pipe);
}

void	close_fd(int number_fd, ...)
{
	va_list	files;

	number_fd++;
	va_start(files, number_fd);
	while (--number_fd)
		close(va_arg(files, int));
}
