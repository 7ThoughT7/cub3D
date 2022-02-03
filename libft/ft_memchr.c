/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:47:24 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:47:24 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*srs;

	srs = (char *)s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*srs == c)
			return (srs);
		srs++;
	}
	return (NULL);
}
