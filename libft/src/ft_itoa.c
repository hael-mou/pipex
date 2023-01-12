/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:21:39 by hael-mou          #+#    #+#             */
/*   Updated: 2022/10/08 15:29:57 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitlen(long long n);
static void	ft_memdigit(char *dst, long long n);

char	*ft_itoa(int n)
{
	char		*str;
	long long	g;

	g = n;
	str = (char *)ft_calloc(ft_digitlen(g) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (g == 0)
		return (ft_memmove(str, "0", 1));
	else
	{
		if (g < 0)
		{
			g *= -1;
			ft_memmove(str, "-", 1);
		}
		ft_memdigit(str, g);
	}
	return (str);
}

static int	ft_digitlen(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_memdigit(char *dst, long long n)
{
	if (n > 9)
	{
		ft_memdigit(dst, n / 10);
		ft_memdigit(dst, n % 10);
	}
	else
	{
		while (*dst)
			dst++;
		*dst = n + '0';
	}
}
