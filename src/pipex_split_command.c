/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:46:23 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/10 10:44:49 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_command(char *string)
{
	int		narg;
	int		sep;
	char	**cmd;
	int		i;

	i = 0;
	if (!string)
		return (NULL);
	if (*string == 34 || *string == 39)
		sep = *string++;
	else
		sep = 32;
	narg = number_argument(string, sep);
	cmd = ft_calloc(narg + 1, sizeof(char *));
	if (!cmd)
		return (NULL);
	while (i < narg)
	{
		cmd[i++] = fill(string, sep);
		while (*string && *string != sep)
			string++;
		while (ft_issep(*string))
			sep = *string++;
	}
	return (cmd);
}

int	number_argument(char *s, char sep)
{
	int	count;

	count = 0;
	while (s && *s)
	{
		while (*s && *s != sep)
			s++;
		count++;
		while (ft_issep(*s))
			sep = *s++;
	}
	return (count);
}

int	ft_issep(char c)
{
	return (c == 34 || c == 32 || c == 39);
}

char	*fill(char *s, char sep)
{
	int		len;
	char	*arg;

	len = 0;
	while (s[len] && s[len] != sep)
		len++;
	arg = ft_calloc(len + 1, 1);
	if (!arg)
		return (NULL);
	ft_memcpy(arg, s, len);
	return (arg);
}
