/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:58:32 by pfaust            #+#    #+#             */
/*   Updated: 2018/10/11 12:31:29 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digits(unsigned long long n, unsigned int base)
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
char			*ft_itoa_base_ll(long long n, unsigned int base)
{
	int			len;
	char		*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = digits(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (--len >= 0)
	{
		if (n % base < 10)
			str[len] = n % base + 48;
		else
			str[len] = n % base - 10 + 'a';
		n = n / base;
	}
	return (str);
}
