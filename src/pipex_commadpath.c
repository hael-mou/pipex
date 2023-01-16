/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commadpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:13:18 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/13 20:14:44 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath_from_env(char **env)
{
	while (env && *env && !ft_strnstr(*env, "PATH=", 5))
		env++;
	if (!env || !*env)
		return (PATH);
	return (*env + 5);
}

char	*whereis_command(char *command, char *path)
{
	int		pathlen;
	char	*command_location;
	int		isfound;

	while (command && path && *path)
	{
		pathlen = 0;
		while (path[pathlen] && path[pathlen] != ':')
			pathlen++;
		command_location = join_command_path(command, path, pathlen);
		isfound = access(command_location, F_OK);
		if (isfound == F_OK)
			return (command_location);
		free(command_location);
		if (path[pathlen] == ':')
			pathlen++;
		path += pathlen;
	}
	if (!path && access(command, F_OK) == F_OK)
		return (ft_strdup(command));
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
