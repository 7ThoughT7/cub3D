/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_calculate_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:27:22 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 17:13:34 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_img1(t_print_data *vel, t_map *map, int x)
{
	vel->camera_x = 2 * x / (double)map->lodev.w - 1;
	vel->ray_dir_x = map->lodev.dir_x + map->lodev.plane_x * vel->camera_x;
	vel->ray_dir_y = map->lodev.dir_y + map->lodev.plane_y * vel->camera_x;
	vel->map_x = (int)(map->lodev.pos_x);
	vel->map_y = (int)(map->lodev.pos_y);
	vel->delta_dist_x = fabs(1 / vel->ray_dir_x);
	vel->delta_dist_y = fabs(1 / vel->ray_dir_y);
	vel->hit = 0;
}

void	calculate_img2(t_print_data *vel, t_map *map)
{
	if (vel->ray_dir_x < 0)
	{
		vel->step_x = -1;
		vel->side_dist_x = (map->lodev.pos_x - vel->map_x) * vel->delta_dist_x;
	}
	else
	{
		vel->step_x = 1;
		vel->side_dist_x = (vel->map_x + 1.0 - map->lodev.pos_x) \
			* vel->delta_dist_x;
	}
	if (vel->ray_dir_y < 0)
	{
		vel->step_y = -1;
		vel->side_dist_y = (map->lodev.pos_y - vel->map_y) * vel->delta_dist_y;
	}
	else
	{
		vel->step_y = 1;
		vel->side_dist_y = (vel->map_y + 1.0 - map->lodev.pos_y) \
			* vel->delta_dist_y;
	}
}

void	calculate_img3(t_print_data *vel, t_map *map)
{
	while (vel->hit == 0)
	{
		if (vel->side_dist_x < vel->side_dist_y)
		{
			vel->side_dist_x += vel->delta_dist_x;
			vel->map_x += vel->step_x;
			vel->side = 0;
		}
		else
		{
			vel->side_dist_y += vel->delta_dist_y;
			vel->map_y += vel->step_y;
			vel->side = 1;
		}
		if (map->field[vel->map_x][vel->map_y] == '1')
			vel->hit = 1;
	}
}

void	calculate_img4(t_print_data *vel, t_map *map)
{
	if (vel->side == 0)
		vel->perp_wall_dist = (vel->map_x - map->lodev.pos_x
				+ (1 - vel->step_x) / 2) / vel->ray_dir_x;
	else
		vel->perp_wall_dist = (vel->map_y - map->lodev.pos_y
				+ (1 - vel->step_y) / 2) / vel->ray_dir_y;
	vel->line_height = (int)(map->lodev.h / vel->perp_wall_dist);
	vel->draw_start = -vel->line_height / 2 + map->lodev.h / 2;
	if (vel->draw_start < 0)
		vel->draw_start = 0;
	vel->draw_end = vel->line_height / 2 + map->lodev.h / 2;
	if (vel->draw_end >= map->lodev.h)
		vel->draw_end = map->lodev.h - 1;
	if (vel->side == 0)
		vel->wall_x = map->lodev.pos_y + vel->perp_wall_dist * vel->ray_dir_y;
	else
		vel->wall_x = map->lodev.pos_x + vel->perp_wall_dist * vel->ray_dir_x;
}

void	calculate_img5(t_print_data *vel, t_map *map)
{
	vel->wall_x = vel->wall_x - (int)(vel->wall_x);
	vel->num_text = num_of_text(vel->side, vel->step_y, vel->step_x);
	vel->tex_x = (int)(vel->wall_x * (double)
			(map->text[vel->num_text].sprites_width));
	if (vel->side == 0 && vel->ray_dir_x > 0)
		vel->tex_x = map->text[vel->num_text].sprites_width - vel->tex_x - 1;
	if (vel->side == 1 && vel->ray_dir_y < 0)
		vel->tex_x = map->text[vel->num_text].sprites_width - vel->tex_x - 1;
	vel->step = 1.0 * map->text[0].sprites_height / vel->line_height;
	vel->tex_pos = (vel->draw_start - map->lodev.h / 2 + \
	vel->line_height / 2) * vel->step;
}
