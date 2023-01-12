/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:26:02 by hael-mou          #+#    #+#             */
/*   Updated: 2022/09/30 16:02:40 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	int		sin;
	int		total;
	char	*str2;

	total = 0;
	sin = 1;
	str2 = (char *)str;
	while (ft_isspace(*str2))
		str2++;
	if (*str2 == '-' || *str2 == '+')
	{
		if (*str2 == '-')
			sin = -1;
	str2++;
	}
	while (ft_isdigit(*str2))
	{
		total = total * 10 + (*str2) - '0';
		str2++;
	}
	return (total * sin);
}

static int	ft_isspace(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	if (c == '\v' || c == '\f')
		return (1);
	if (c == '\n' || c == '\r')
		return (1);
	return (0);
}
