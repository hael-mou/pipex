/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:18:32 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/15 19:30:07 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	isheredoc(char **argument)
{
	return (!ft_strcmp(argument[1], "here_doc", 0));
}

void	ft_heredoc(int *pipes, char *limiter)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0);
		if (!ft_strcmp(line, limiter, 1))
			break ;
		ft_putstr_fd(line, pipes[1]);
	}
	exit(0);
}
