/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:48:18 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:48:18 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *distan, const void *source, size_t n)
{
	char	*dis;
	char	*srs;
	int		i;

	i = 0;
	if (n == 0)
		return (distan);
	if (distan <= source)
	{
		ft_memcpy(distan, source, n);
		return (distan);
	}
	dis = (char *)distan + n - 1;
	srs = (char *)source + n - 1;
	while (n)
	{
		dis[i] = srs[i];
		i--;
		n--;
	}
	return (distan);
}
