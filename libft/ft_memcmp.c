/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:47:33 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:47:33 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*sor1;
	char	*sor2;

	sor1 = (char *)s1;
	sor2 = (char *)s2;
	while ((*sor1 == *sor2) && (--n))
	{
		sor1++;
		sor2++;
	}
	if (!n)
		return (0);
	return ((unsigned char)*sor1 - (unsigned char)*sor2);
}
