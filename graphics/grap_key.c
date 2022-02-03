/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:34:18 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 17:02:54 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	key_hook_press_take(int keycode, t_map *map);
static void	key_hook_press_take_minimap(int keycode, t_map *map);
static void	key_hook_press_turn_r(t_map *map);
static void	key_hook_press_turn_l(t_map *map);

int	key_hook_press(int keycode, t_map *map)
{
	double	test_pos_x;
	double	test_pos_y;

	mlx_destroy_image(map->grap.mlx, map->grap.img);
	map->grap.img = mlx_new_image(map->grap.mlx, map->spec.r.x, map->spec.r.y);
	if (map->grap.img == NULL)
		error(38);
	map->grap.addr = mlx_get_data_addr(map->grap.img, \
	&map->grap.bits_per_pixel, &map->grap.line_length, &map->grap.endian);
	test_pos_x = map->lodev.pos_x;
	test_pos_y = map->lodev.pos_y;
	key_hook_press_take(keycode, map);
	if (map->button.up == 1 && map->button.down == 0)
		move_forward(map, 1, &test_pos_x, &test_pos_y);
	else if (map->button.down == 1 && map->button.up == 0)
		move_forward(map, -1, &test_pos_x, &test_pos_y);
	if (map->button.right == 1 && map->button.left == 0)
		move_side(map, 1, &test_pos_x, &test_pos_y);
	else if (map->button.left == 1 && map->button.right == 0)
		move_side(map, -1, &test_pos_x, &test_pos_y);
	key_hook_press_turn_r(map);
	key_hook_press_turn_l(map);
	change_player_position(map, test_pos_x, test_pos_y);
	ft_map_print(map);
	return (1);
}

static void	key_hook_press_take(int keycode, t_map *map)
{
	if (keycode == Esc)
	{
		printf("Exit\n");
		mlx_destroy_window(map->grap.mlx, map->grap.win);
		exit (0);
	}
	else if (keycode == Up && map->button.up == 0)
		map->button.up = 1;
	else if (keycode == Down && map->button.down == 0)
		map->button.down = 1;
	else if (keycode == Right && map->button.right == 0)
		map->button.right = 1;
	else if (keycode == Left && map->button.left == 0)
		map->button.left = 1;
	else if (keycode == Turn_right && map->button.turn_right == 0)
		map->button.turn_right = 1;
	else if (keycode == Turn_left && map->button.turn_left == 0)
		map->button.turn_left = 1;
	else
		key_hook_press_take_minimap(keycode, map);
}

static void	key_hook_press_take_minimap(int keycode, t_map *map)
{
	if (keycode == M)
	{
		if (map->mini_map.size == 4)
			map->mini_map.size = 0;
		else
			map->mini_map.size++;
	}
	else if (keycode == F)
	{
		if (map->mini_map.mode == 2)
			map->mini_map.mode = 0;
		else
			map->mini_map.mode++;
	}
}

static void	key_hook_press_turn_r(t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;

	if (map->button.turn_right == 1 && map->button.turn_left == 0)
	{
		old_dir_x = map->lodev.dir_x;
		map->lodev.dir_x = map->lodev.dir_x * cos(-map->lodev.rot_speed) - \
		map->lodev.dir_y * sin(-map->lodev.rot_speed);
		map->lodev.dir_y = old_dir_x * sin(-map->lodev.rot_speed) + \
		map->lodev.dir_y * cos(-map->lodev.rot_speed);
		old_plane_x = map->lodev.plane_x;
		map->lodev.plane_x = map->lodev.plane_x * cos(-map->lodev.rot_speed) - \
		map->lodev.plane_y * sin(-map->lodev.rot_speed);
		map->lodev.plane_y = old_plane_x * sin(-map->lodev.rot_speed) + \
		map->lodev.plane_y * cos(-map->lodev.rot_speed);
	}
}

static void	key_hook_press_turn_l(t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;

	if (map->button.turn_left == 1 && map->button.turn_right == 0)
	{
		old_dir_x = map->lodev.dir_x;
		map->lodev.dir_x = map->lodev.dir_x * cos(map->lodev.rot_speed) - \
		map->lodev.dir_y * sin(map->lodev.rot_speed);
		map->lodev.dir_y = old_dir_x * sin(map->lodev.rot_speed) + \
		map->lodev.dir_y * cos(map->lodev.rot_speed);
		old_plane_x = map->lodev.plane_x;
		map->lodev.plane_x = map->lodev.plane_x * cos(map->lodev.rot_speed) - \
		map->lodev.plane_y * sin(map->lodev.rot_speed);
		map->lodev.plane_y = old_plane_x * sin(map->lodev.rot_speed) + \
		map->lodev.plane_y * cos(map->lodev.rot_speed);
	}
}
