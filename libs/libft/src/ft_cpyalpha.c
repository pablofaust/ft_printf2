/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:29:33 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:24:52 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_alpha(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_cpyalpha(char *str)
{
	char	*cpy;
	int	len;
	int	i;
	int	j;

	if (!str)
		return (NULL);
	if (!(len = ft_count_alpha(str)))
		return (NULL);
	if (!(cpy = ft_strnew(len)))
		return (NULL);
	i = 0;
	j = 0;
	while (j > len)
	{
		if (ft_isalpha(str[i]))
			cpy[j++] = str[i];
		i++;
	}
	return (cpy);
}
