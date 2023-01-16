/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:46:23 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/13 16:56:38 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	*split_all_cmd(int ncmd, char **argument, char *path, int isherdoc)
{
	t_command	*cmd;
	int			id;

	id = -1 + isherdoc;
	cmd = ft_calloc(ncmd + 1, sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd[0].id = 0;
	while (++id < ncmd)
	{
		cmd[id].id = -1;
		cmd[id].isexecutable = NO;
		cmd[id].argument = split_command(argument[id]);
		if (!cmd[id].argument)
			clean_all(cmd, NULL, NULL, NO);
		if (cmd[id].argument[0][0] != '.' && !ft_strchr(cmd[id].argument[0], '/'))
			cmd[id].path = whereis_command(cmd[id].argument[0], path);
		else
			cmd[id].path = whereis_command(cmd[id].argument[0], NULL);
		if (cmd[id].path)
			cmd[id].isexecutable = !access(cmd[id].path, X_OK);
		cmd[id].id = id;
	}
	cmd[id].id = -1;
	return (cmd);
}

char	**split_command(char *string)
{
	int		narg;
	char	sep;
	char	**cmd;
	int		i;

	i = -1;
	sep = 32;
	if (!string)
		return (NULL);
	if (*string == 34 || *string == 39)
		sep = *string++;
	narg = number_argument(string, sep);
	cmd = ft_calloc(narg + 1, sizeof(char *));
	if (!cmd)
		return (NULL);
	while (++i < narg)
	{
		cmd[i] = fill(string, sep);
		if (!cmd[i])
			free_argument(cmd);
		while (*string && *string != sep)
			string++;
		string = skip_sep(string, &sep);
	}
	return (cmd);
}

int	number_argument(char *string, char sep)
{
	int	count;

	count = 0;
	while (string && *string)
	{
		while (*string && *string != sep)
			string++;
		count++;
		string = skip_sep(string, &sep);
	}
	return (count);
}

char	*skip_sep(char *string, char *sep)
{
	while (*string == 34 || *string == 32 || *string == 39)
	{
		if ((*sep == 34 && *string == 39) || (*sep == 39 && *string == 34))
			break ;
		*sep = *string++;
	}
	return (string);
}

char	*fill(char *string, char sep)
{
	int		len;
	char	*arg;

	len = 0;
	while (string[len] && string[len] != sep)
		len++;
	arg = ft_calloc(len + 1, 1);
	if (!arg)
		return (NULL);
	ft_memmove(arg, string, len);
	return (arg);
}
