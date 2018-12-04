/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:57:48 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:25:21 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dir_strncpy(char *src, int n, char c)
{
	char	*cpy;	
	int		i;
	int		j;

	if (!src || (c != '<' && c != '>'))
		return (NULL);
	if (!(cpy = ft_strnew(n)))
		return (NULL);
	j = 0;
	i = (c == '<') ? 0 : ft_strlen(src) - n;
	while (j < n)
		cpy[j++] = src[i++];
	return (cpy);
}
