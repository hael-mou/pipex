/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:28:38 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/01 18:48:38 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	tmp;

	tmp = 0;
	if (!dst && !src)
		return (NULL);
	while (n > tmp)
	{
		*((unsigned char *)dst + tmp) = *((unsigned char *)src + tmp);
		tmp++;
	}
	return (dst);
}
