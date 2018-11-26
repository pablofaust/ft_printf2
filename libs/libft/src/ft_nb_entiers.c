/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_entiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:33:39 by pfaust            #+#    #+#             */
/*   Updated: 2018/11/26 11:34:10 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nb_entiers(double n)
{
	int		entiers;
	int		lon;

	entiers = ABS((int)n);
	lon = 0;
	while (entiers > 0)
	{
		entiers = entiers / 10;
		lon++;
	}
	return (lon);
}
