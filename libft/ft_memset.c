/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:48:26 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:48:26 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*buf;

	buf = (char *)b;
	i = 0;
	while (len > 0)
	{
		buf[i] = c;
		i++;
		len--;
	}
	return (b);
}
