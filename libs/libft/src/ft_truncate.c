/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:29:33 by pfaust            #+#    #+#             */
/*   Updated: 2018/11/26 11:40:14 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_truncate(char *str, int n, char c)
{
	int	len;
	char	*chunk;
	int	i;
	int	j;

	if (!str || !n || (c != '<' && c != '>'))
		return (NULL);
	len = ft_strlen(str) - n;
	if (!(chunk = ft_strnew(len)))
		return (NULL);
	j = 0;
	i = (c == '<') ? n - 1 : 0;
	while (j < len)
		chunk[j++] = str[i++];
	return (chunk);
}
