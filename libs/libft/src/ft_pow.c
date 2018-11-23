/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:03:40 by pfaust            #+#    #+#             */
/*   Updated: 2018/11/23 14:26:36 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_pow(unsigned int len)
{
	unsigned int		pow;

	pow = 1;
	if (len == 0)
		return (pow);
	while (--len > 0)
		pow = 10 * pow;
	return (pow);
}
