/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_init_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:02:07 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 15:23:53 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_player_e_w(t_map *map, int i, int j);
static void	init_player_n_s(t_map *map, int i, int j);

void	init_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->column)
		{
			if (map->field[i][j] == 'E' || map->field[i][j] == 'N' || \
				map->field[i][j] == 'W' || map->field[i][j] == 'S')
			{
				map->lodev.posX = i + 0.5;
				map->lodev.posY = j + 0.5;
				init_player_n_s(map, i, j);
			}
			j++;
		}
		i++;
	}
	map->lodev.w = map->spec.r.x;
	map->lodev.h = map->spec.r.y;
	map->lodev.moveSpeed = 0.2;
	map->lodev.rotSpeed = 0.085;
}

static void	init_player_n_s(t_map *map, int i, int j)
{
	if (map->field[i][j] == 'N')
	{
		map->lodev.dirX = -1.0;
		map->lodev.dirY = 0;
		map->lodev.planeX = 0;
		map->lodev.planeY = 0.66;
	}
	else if (map->field[i][j] == 'S')
	{
		map->lodev.dirX = 1.0;
		map->lodev.dirY = 0;
		map->lodev.planeX = 0;
		map->lodev.planeY = -0.66;
	}
	else
		init_player_e_w(map, i, j);
}

static void	init_player_e_w(t_map *map, int i, int j)
{
	if (map->field[i][j] == 'E')
	{
		map->lodev.dirX = 0;
		map->lodev.dirY = 1;
		map->lodev.planeX = 0.66;
		map->lodev.planeY = 0;
	}
	else if (map->field[i][j] == 'W')
	{
		map->lodev.dirX = 0;
		map->lodev.dirY = -1.0;
		map->lodev.planeX = -0.66;
		map->lodev.planeY = 0;
	}
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
