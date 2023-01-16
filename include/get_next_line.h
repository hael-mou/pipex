/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:12:53 by hael-mou          #+#    #+#             */
/*   Updated: 2023/01/15 12:16:02 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define YES 1
# define NO 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif

//principal function :
char	*get_next_line(int fd);
char	*ft_readblock(int fd, char *str);
char	*ft_subblock(char *str, char *backup);

//utils function :
int		ft_isendline(char *str);
char	*ft_realloc(char *str, size_t size, int *oldlen, char free_str);

#endif
