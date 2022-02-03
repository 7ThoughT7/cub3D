/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:45:48 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:45:48 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*s;

	if (number == (size_t)0 || size == (size_t)0)
	{
		number = (size_t)1;
		size = (size_t)1;
	}
	s = malloc(number * size);
	if (s == NULL)
		return (NULL);
	else
		s = ft_bzero(s, number * size);
	return (s);
}
