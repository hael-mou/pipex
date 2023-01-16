/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:11:30 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/08 15:41:33 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2, int index)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] != '\0'
	&& ((unsigned char *)s2)[i] != '\0'
	&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (index && s1[i] == '\n')
		s1++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
