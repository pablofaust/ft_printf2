/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:16:23 by pfaust            #+#    #+#             */
/*   Updated: 2018/10/24 21:08:00 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int		digits(unsigned int n, int base)
{
	unsigned int		ptr;
	int					len;

	ptr = n;
	if (n == 0)
		return (1);
	len = 0;
	while (ptr)
	{
		ptr = ptr / base;
		len++;
	}
	return (len);
}
char			*ft_itoa_base_uint(unsigned int nb, int base, char a)
{
	int				len;
	char			*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = digits(nb, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (--len >= 0)
	{
		if (nb % base < 10)
			str[len] = nb % base + 48;
		else
			str[len] = (a == 'a') ? nb % base - 10 + 'a' : nb % base - 10 + 'A';
		nb = nb / base;
	}
	return (str);
}
