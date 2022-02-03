/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:49:12 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:49:12 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	while (*src != c && *src)
		src++;
	if (*src == c)
		return ((char *)src);
	return (0);
}
