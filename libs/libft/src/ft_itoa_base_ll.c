/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:58:32 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:25:42 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base_pow(unsigned long long n, unsigned int base)
{
	if (n == 0)
		return (0);
	else
		return (1 + ft_base_pow(n / base, base));
}

char			*ft_itoa_base_ll(long long n, unsigned int base)
{
	char			*res;
	unsigned long long	tmp;
	int			pow;

	pow = (n == 0) ? 1 : ft_base_pow(n, base);
	tmp = n;
	if (!(res = ft_strnew(pow)) || base < 2 || base > 16)
		return (NULL);
	while (--pow >= 0)
	{
		res[pow] = (tmp % base < 10) ? tmp % base + 48 : tmp % base - 10 + 'a';
		tmp = tmp / base;
	}
	return (res);
}
