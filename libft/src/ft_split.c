/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:38:40 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/08 21:22:40 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numtable(char const *s, char c);
static char	*ft_dev(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		number;
	char	**str;
	char	*string;

	if (!s)
		return (0);
	number = ft_numtable(s, c);
	str = (char **)ft_calloc((number + 1), sizeof(char *));
	if (!str)
		return (NULL);
	number = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			string = ft_dev(s, c);
			str[number] = string;
			number++;
		}
		while (*s && *s != c)
			s++;
	}
	return (str);
}

static int	ft_numtable(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_dev(char const *s, char c)
{
	int		wordlen;
	char	*string;

	wordlen = 0;
	while (s[wordlen] && s[wordlen] != c)
		wordlen++;
	string = (char *)ft_calloc((wordlen + 1), sizeof(char));
	if (!string)
		return (NULL);
	ft_memmove(string, s, wordlen);
	return (string);
}
