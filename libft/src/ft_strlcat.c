/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:33:09 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/08 15:55:51 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srcsize;
	size_t	i;

	i = 0;
	dstlen = 0;
	if (!dstsize)
		return (ft_strlen(src));
	srcsize = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen > dstsize)
		return (srcsize + dstsize);
	else if (dstlen < dstsize)
	{
		while (src[i] && (dstlen + i) < (dstsize - 1))
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	return (dstlen + srcsize);
}
