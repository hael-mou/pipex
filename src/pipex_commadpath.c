/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commadpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:13:18 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/10 10:03:21 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath_from_env(char **env)
{
	while (env && *env && !ft_strnstr(*env, "PATH=", 5))
		env++;
	if (!env || !*env || !env[0][5])
		return (PATH);
	return (*env + 5);
}

char	*whereis_command(char *command, char *path)
{
	int		pathlen;
	char	*command_location;

	command_location = NULL;
	while (path && *path && !command_location)
	{
		pathlen = path_length(path);
		command_location = check_command_existence(command, path, pathlen);
		if (path[pathlen] == ':')
			pathlen++;
		path += pathlen;
	}
	free(command);
	return (command_location);
}

int	path_length(char *path)
{
	int	pathlen;

	pathlen = 0;
	while (path[pathlen] && path[pathlen] != ':')
		pathlen++;
	return (pathlen);
}

char	*check_command_existence(char *command, char *path, int pathlen)
{
	char	*command_location;
	int		found;

	if (!pathlen)
		return (NULL);
	command_location = join_command_path(command, path, pathlen);
	found = access(command_location, F_OK);
	if (found == F_OK)
		return (command_location);
	free(command_location);
	return (NULL);
}

char	*join_command_path(char *command, char *path, int pathlen)
{
	char	*command_and_path;
	int		commandlen;

	if (!command || !path)
		return (NULL);
	commandlen = ft_strlen(command);
	command_and_path = ft_calloc(pathlen + commandlen + 2, sizeof(char));
	if (!command_and_path)
		return (NULL);
	ft_memmove(command_and_path, path, pathlen);
	command_and_path[pathlen++] = '/';
	ft_memmove(command_and_path + pathlen, command, commandlen);
	return (command_and_path);
}
