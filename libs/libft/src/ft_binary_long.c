/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:07:11 by pfaust            #+#    #+#             */
/*   Updated: 2018/11/27 10:52:06 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_binary_long(long n)
{
	unsigned char	octet;
	int				i;

	printf("long = %ld\n", n);
	i = 4;
	while (i)
	{
		printf("octect n %d\n", i);
		octet = (unsigned char)n;
		ft_print_bits(octet);
		n <<= 4;
		i--;
	}
}
