/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:16:23 by pfaust            #+#    #+#             */
/*   Updated: 2018/11/20 10:10:30 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int		itoapow(unsigned int n, int base)
{
	if (n == 0)
		return (0);
	else
		return (1 + itoapow(n / base, base));
}

char			*ft_itoa_base(int n, int base)
{
	char			*total;
	unsigned int	tmp;
	int				i;

	i = itoapow(n, base);
	tmp = n;
	if (n == 0)
		i = 1;
	if (!(total = ft_strnew(i)) || base < 2 || base > 16)
		return (NULL);
	while (--i >= 0)
	{
		total[i] = (tmp % base < 10) ? tmp % base + 48 : tmp % base - 10 + 'a';
		tmp = tmp / base;
	}
	return (total);
}
