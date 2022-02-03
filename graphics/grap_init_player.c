/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_init_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:02:07 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 17:02:54 by bmohamme         ###   ########.fr       */
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
				map->lodev.pos_x = i + 0.5;
				map->lodev.pos_y = j + 0.5;
				init_player_n_s(map, i, j);
			}
			j++;
		}
		i++;
	}
	map->lodev.w = map->spec.r.x;
	map->lodev.h = map->spec.r.y;
	map->lodev.move_speed = 0.2;
	map->lodev.rot_speed = 0.085;
}

static void	init_player_n_s(t_map *map, int i, int j)
{
	if (map->field[i][j] == 'N')
	{
		map->lodev.dir_x = -1.0;
		map->lodev.dir_y = 0;
		map->lodev.plane_x = 0;
		map->lodev.plane_y = 0.66;
	}
	else if (map->field[i][j] == 'S')
	{
		map->lodev.dir_x = 1.0;
		map->lodev.dir_y = 0;
		map->lodev.plane_x = 0;
		map->lodev.plane_y = -0.66;
	}
	else
		init_player_e_w(map, i, j);
}

static void	init_player_e_w(t_map *map, int i, int j)
{
	if (map->field[i][j] == 'E')
	{
		map->lodev.dir_x = 0;
		map->lodev.dir_y = 1;
		map->lodev.plane_x = 0.66;
		map->lodev.plane_y = 0;
	}
	else if (map->field[i][j] == 'W')
	{
		map->lodev.dir_x = 0;
		map->lodev.dir_y = -1.0;
		map->lodev.plane_x = -0.66;
		map->lodev.plane_y = 0;
	}
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
