/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:59:36 by bmohamme          #+#    #+#             */
/*   Updated: 2022/01/26 21:14:19 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_pers(t_game *g, int y, int x)
{
	char	**m;

	m = g->map;
	if (m[y][x] == 'W' || m[y][x] == 'E' || m[y][x] == 'S' || m[y][x] == 'N')
	{
		g->pers++;
		g->pers_y = y;
		g->pers_x = x;
		g->vector = m[y][x];
		m[y][x] = '0';
	}
}

int	check_symbol(t_game *g, int y, int x)
{
	char	**m;

	m = g->map;
	if (m[y][x] == '1' || m[y][x] == '0' || m[y][x] == 'W' || m[y][x] == 'S' ||
	m[y][x] == 'E' || m[y][x] == 'N' || m[y][x] == ' ')
		return (1);
	return (0);
}

void	check_valid_symbol(t_game *g)
{
	int	y;
	int x;

	y = -1;
	g->pers = 0;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			check_pers(g, y, x);
//			if (check_symbol(g, y, x))
//				exit_game(4, g);
		}
	}
//	if (g->pers != 1)
//		exit_game(5, g);
}

void	perimeter_check(t_game *g)
{
	int	y;
	int x;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[0][x] != '1' && g->map[0][x] != ' ')
				exit_game(4, g);
			if (g->map[g->len_y - 1][x] != '1' && g->map[g->len_y - 1][x] != ' ')
				exit_game(4, g);
			if (g->map[y][0] != '1' && g->map[y][0] != ' ')
				exit_game(4, g);
			if (g->map[y][g->len_x - 1] != '1' && g->map[y][g->len_x - 1] != ' ')
				exit_game(4, g);
		}
	}
}

void	check_valid_map(t_game *g)
{
	int	y;
	int x;
	char	**m;

	perimeter_check(g);
	y = 0;
	m = g->map;
	while (m[++y + 1])
	{
		x = 0;
		while (m[y][++x + 1])
		{
			if (m[y][x] == '0')
				if (m[y - 1][x - 1] == ' ' || m[y - 1][x] == ' ' ||
				m[y - 1][x + 1] == ' ' || m[y][x - 1] == ' ' ||
				m[y][x + 1] == ' ' || m[y + 1][x - 1] == ' ' ||
				m[y + 1][x] == ' ' || m[y + 1][x + 1] == ' ')
					exit_game(4, g);
		}
	}
}