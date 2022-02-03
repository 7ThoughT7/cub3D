/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_main_loop_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:42:01 by bmohamme          #+#    #+#             */
/*   Updated: 2022/02/03 16:42:04 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	char_in_str(char cr, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == cr)
			return (1);
	}
	return (0);
}

int	num_of_text(int side, int step_y, int step_x)
{
	if (side == 1)
	{
		if (step_y == -1)
			return (WE);
		else
			return (EA);
	}
	else
	{
		if (step_x == -1)
			return (NO);
		else
			return (SO);
	}
}

int	it_is_not_wall(t_map *map, double row, double col)
{
	if (map->field[(int)row][(int)col] != '0')
		return (0);
	else if (map->field[(int)(row + 0.11)][(int)(col + 0.11)] != '0')
		return (0);
	else if (map->field[(int)(row + 0.11)][(int)(col)] != 48)
		return (0);
	else if (map->field[(int)(row)][(int)(col + 0.11)] != 48)
		return (0);
	else if (map->field[(int)(row - 0.11)][(int)(col - 0.11)] != 48)
		return (0);
	else if (map->field[(int)(row - 0.11)][(int)(col)] != 48)
		return (0);
	else if (map->field[(int)(row)][(int)(col - 0.11)] != 48)
		return (0);
	return (1);
}
