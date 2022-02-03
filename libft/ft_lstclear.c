/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:46:37 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:46:37 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(tmp);
	}
}
