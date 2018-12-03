/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:03:40 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/03 11:08:49 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long			ft_pow(unsigned int len)
{
	unsigned long long		pow;

	pow = 1;
	if (len == 0)
		return (pow);
	while (--len > 0)
		pow = 10 * pow;
	return (pow);
}
