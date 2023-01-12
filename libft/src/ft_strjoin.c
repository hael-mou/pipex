/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:10:29 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/06 15:51:33 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*total;
	size_t	ds1;
	size_t	ds2;

	if (!s1 || !s2)
		return (NULL);
	ds1 = ft_strlen(s1);
	ds2 = ft_strlen(s2);
	total = (char *)ft_calloc((ds1 + ds2 + 1), sizeof(char));
	if (!total)
		return (NULL);
	ft_memcpy(total, s1, ds1);
	ft_memmove(total + ds1, s2, ds2 + 1);
	return (total);
}
