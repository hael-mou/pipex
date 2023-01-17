/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:39:27 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/15 19:31:00 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
##############################################################
#  	   * Include :		    								 #
##############################################################*/
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

/*
##############################################################
#  	   * Macro definition :									 #
##############################################################*/
# define MIN_ARGUMENT_ALLOW	5
# define YES 1
# define NO 0
# define PATH	"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"
# define IS_CHILD 0
# define NO_PERMISSION -1
# define FILE_NOT_FOUND -1
# define PIPE_ERROR -1

/*
##############################################################
#  	   * Struct :											 #
##############################################################*/
typedef struct s_command
{
	int		id;
	pid_t	pid;
	char	**arg;
	char	*path;
	int		isexecutable;
	int		exit_status;
}	t_command;

typedef struct s_files
{
	char	*infile;
	char	*outfile;
	int		isheredoc;
	char	*limiter;
}	t_files;

/*
##############################################################
#  	   * Functions :		    							 #
##############################################################*/
// pipex_commandpath
char		*getpath_from_env(char **env);
char		*whereis_command(char *command, char *path);
char		*join_command_path(char *command, char *path, int pathlen);

// pipex_split_command
t_command	*split_all_cmd(int ncmd, char **argument, char *path, int isherdoc);
char		**split_command(char *string);
int			number_argument(char *string, char sep);
char		*skip_sep(char *string, char *sep);
char		*fill(char *string, char sep);

// pipex_files
t_files		*getfiles(char **argument, int number_argument);
int			*create_pipes(int number_command);
void		close_pipes(int	*pipes);
int			open_infile(char *infile);
int			open_outfile(char *outfile, int isheredoc);

// pipex_execute
void		execute_cmd(t_command *cmd, int *pipes, t_files *files, char **env);
void		io_command(t_command *cmd, int *pipes, t_files *files);
int			wait_allproccess(t_command *command);

// ft_perror
void		ft_perror(const char *s);
void		ft_error(int fd, t_command *command);

// heredoc
int			isheredoc(char **argument);
void		ft_heredoc(int *pipes, char *limiter);

// clean
void		clean_all(t_command *cmd, t_files *files, int *pipes, int isexit);
void		free_argument(char **argument);

#endif //PIPEX_H 
