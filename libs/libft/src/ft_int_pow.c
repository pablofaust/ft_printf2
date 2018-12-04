/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:03:40 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:25:28 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_int_pow(unsigned long long n)
{
	unsigned long long	pow;

	pow = 1;
	while (n >= 10)
	{
		n = n / 10;
		pow = pow * 10;
	}
	return (pow);
}
