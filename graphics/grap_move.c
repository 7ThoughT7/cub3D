/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:44:27 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 17:02:54 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_player_position(t_map *map, double row, double col)
{
	if (it_is_not_wall(map, row, col))
	{
		map->lodev.pos_x = row;
		map->lodev.pos_y = col;
	}
}

void	move_forward(t_map *map, int flag, double *x, double *y)
{
	*x += flag * map->lodev.dir_x * (map->lodev.move_speed);
	*y += flag * map->lodev.dir_y * (map->lodev.move_speed);
}

void	move_side(t_map *map, int flag, double *x, double *y)
{
	*y -= flag * map->lodev.dir_x * (map->lodev.move_speed);
	*x += flag * map->lodev.dir_y * (map->lodev.move_speed);
}
