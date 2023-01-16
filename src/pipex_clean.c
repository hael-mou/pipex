/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:43:28 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/16 12:43:52 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_all(t_command *command, t_files *files, int *pipes, int isexit)
{
	int	i;
	int	j;

	i = 0;
	if (files && files->isheredoc)
		i = 1;
	if (files)
		free(files);
	if (pipes)
		free(pipes);
	while (command && command[i].id != -1)
	{
		j = 0;
		free(command[i].path);
		free_argument(command[i].argument);
		i++;
	}
	free(command);
	if (isexit)
		exit(EXIT_FAILURE);
}

void	free_argument(char **argument)
{
	int	i;

	i = 0;
	while (argument && argument[i])
	{
		free(argument[i]);
		argument[i++] = NULL;
	}
	free(argument);
}
