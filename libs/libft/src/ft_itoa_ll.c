/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 09:16:02 by pfaust            #+#    #+#             */
/*   Updated: 2018/10/17 09:19:00 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long			ft_expo(int len)
{
	long long	exp;

	exp = 1;
	while (len > 0)
	{
		exp = exp * 10;
		len--;
	}
	return (exp);
}

static int				ft_itoalen(long long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa_ll(long long n)
{
	int			neg;
	unsigned long long	tmp;
	long long		len;
	char			*res;
	int			i;
	
	i = 0;
	neg = (n < 0) ? 1 : 0;
	tmp = ABS(n);
	len = ft_itoalen(tmp);
	if (!(res = ft_strnew(len + neg)))
		return (NULL);
	len = ft_expo(len - 1);
	if (neg)
		res[i++] = '-';
	while (len)
	{
		res[i++] = (tmp / len) + 48;
		tmp = tmp % len;
		len = len / 10;
	}
	return (res);
}
