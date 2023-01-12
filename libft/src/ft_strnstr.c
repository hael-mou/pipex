/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:50:31 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/08 11:27:17 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (j < len && haystack[j])
	{
		i = 0;
		while (needle[i])
		{
			if (needle[i] != haystack[j + i] || !(j + i < len))
				break ;
			i++;
		}
		if (!needle[i])
			return ((char *)haystack + j);
		j++;
	}
	return (NULL);
}
