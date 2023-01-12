/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:49:52 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/12 11:45:05 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int	main(int ac, char **av)
{
	int	*pfd;
	int	fd;
	int	pid;

	pfd = malloc(4 * sizeof(int));
	pipe(pfd);
	pipe(pfd + 2);
	fd = open("/dev/urandom", O_RDONLY);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 0);
		dup2(pfd[1], 1);
		close(fd);
		close(pfd[1]);
		close(pfd[0]);
		execlp("cat", "cat", NULL);
		exit(1);
	}
	close(fd);
	close(pfd[1]);
	close(pfd[0]);
	waitpid(pid, NULL, 0);
	return (0);
}
