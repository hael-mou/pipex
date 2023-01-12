/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:25:07 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/08 19:58:09 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *sep);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	while (check(*s1, set))
		s1++;
	if (*s1 == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	len = ft_strlen(s1);
	while (check(*(s1 + len - 1), set))
		len--;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, len);
	return (str);
}

static int	check(char c, char const *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}
