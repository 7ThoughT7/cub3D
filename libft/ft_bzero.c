/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:45:42 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:45:42 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_bzero(void *s, size_t len)
{
	int		i;
	char	*buf;

	buf = (char *)s;
	i = 0;
	while (i < (int)len)
	{
		buf[i] = 0;
		i++;
	}
	return (s);
}
