/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:07:11 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:24:42 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_binary_long(long n)
{
	unsigned char	octet;
	int				i;

	i = 4;
	while (i)
	{
		octet = (unsigned char)n;
		ft_print_bits(octet);
		n <<= 4;
		i--;
	}
}
