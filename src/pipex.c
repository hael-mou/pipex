/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:08:36 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/15 16:29:28 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_command	*command;
	t_files		*files;
	char		*path;
	int			*pipes;
	int			index;

	index = -1;
	if (argc < MIN_ARGUMENT_ALLOW)
		return (EXIT_FAILURE);
	path = getpath_from_env(env);
	files = getfiles(argv, argc);
	pipes = create_pipes(argc - 3);
	if (!pipes)
		clean_all(NULL, files, NULL, YES);
	command = split_all_cmd(argc - 3, argv + 2, path, files->isheredoc);
	if (!command)
		clean_all(NULL, files, pipes, YES);
	while (command[++index].id != -1)
		execute_cmd(&command[index], pipes, files, env);
	close_pipes(pipes);
	index = wait_allproccess(command);
	clean_all(command, files, pipes, NO);
	return (index);
}
