/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:48:26 by bmohamme          #+#    #+#             */
/*   Updated: 2021/12/03 19:49:25 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print(t_game *g)
{
	int i;

	i = -1;
	while (g->map[++i])
		printf("%s\n", g->map[i]);
}



int main(int ac, char **av)
{
	t_game	g;
	(void )ac;
	read_file(&g, av);
	print(&g);
//	while (1);
	return (0);
}