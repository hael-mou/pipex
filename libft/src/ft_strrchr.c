/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:54:43 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/01 15:55:31 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(s);
	tmp = (char *)s + len;
	while (tmp >= s)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp--;
	}
	return (0);
}
