/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:39:27 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/11 13:03:08 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
##############################################################
#  	   * Include :		    								 #
##############################################################*/
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

/*
##############################################################
#  	   * Macro definition :									 #
##############################################################*/
# define MIN_ARGUMENT_ALLOW	5
# define PIPE_ERROR	-1
# define NO_PERMISSION -1
# define FILE_NOT_FOUND -1
# define PATH	"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"
# define IS_CHILD 0

/*
##############################################################
#  	   * Struct :											 #
##############################################################*/
typedef struct s_command
{
	int		id;
	int		process_id;
	char	**argument;
	int		infile;
	int		outfile;
}	t_command;

/*
##############################################################
#  	   * Functions :		    							 #
##############################################################*/
// pipex_commandpath
char	*getpath_from_env(char **env);
char	*whereis_command(char *command, char *path);
char	*check_command_existence(char *command, char *path, int pathlen);
char	*join_command_path(char *command, char *path, int pathlen);
int		path_length(char *path);

// pipex_split_command
char	**split_command(char *string);
int		number_argument(char *s, char sep);
int		ft_issep(char c);
char	*fill(char *s, char sep);

// pipex_files
int		open_infile(char *infile);
int		open_outfile(char *outfile);
int		*create_pipes(int number_command);
void	close_fd(int number, ...);

// pipex_error
void	ft_perror(const char *s);

#endif //PIPEX_H 
