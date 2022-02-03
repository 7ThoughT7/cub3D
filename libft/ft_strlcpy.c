/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:49:56 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:49:56 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	char	*d;
	char	*s;

	if (dst == NULL)
		return (dstsize);
	if (dstsize == 0)
		return (ft_strlen(src));
	d = dst;
	s = (char *)src;
	i = 0;
	while (i < (int)dstsize - 1)
	{
		if (!s[i])
		{
			d[i] = 0;
			return (ft_strlen(src));
		}
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (ft_strlen(src));
}
