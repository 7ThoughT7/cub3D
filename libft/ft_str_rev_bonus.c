/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rev_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:49:06 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:49:06 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_rev(char *str)
{
	int		i;
	int		j;
	char	s;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		s = str[i];
		str[i] = str[j];
		str[j] = s;
		j--;
		i++;
	}
}
