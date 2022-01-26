/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit_func_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:48:37 by bmohamme          #+#    #+#             */
/*   Updated: 2022/01/26 21:31:06 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_game(int i, t_game *g)
{
	if (i == 1)
		printf("Invalid map\n");
	else if (i == 2)
	{
		free(g->image);
		printf("Invalid param\n");
	}
	else if (i == 3)
	{
		free(g->image);
		printf("Invalid image\n");
	}
	else if (i == 4)
	{
		free(g->image);
		free_map(g);
		printf("Invalid map2\n");
	}
	else if (i == 5)
	{
		free(g->image);
		free_map(g);
		printf("Invalid number of characters\n");
	}
	exit(1);
}

void	free_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	check_valid_param(t_game *g)
{
	t_image *i;

	i = g->image;
	if(!i->no || !i->so || !i->we || !i->ea)
		exit_game(2, g);
	if (open(i->no, O_RDONLY) == -1)
		exit_game(3, g);
	if (open(i->so, O_RDONLY) == -1)
		exit_game(3, g);
	if (open(i->we, O_RDONLY) == -1)
		exit_game(3, g);
	if (open(i->ea, O_RDONLY) == -1)
		exit_game(3, g);
}

void	pars_color_f(char **arr, t_game *g)
{
	int	i;
	int	rgb[3];

	i = -1;
	while (++i < 3 && arr[i])
		rgb[i] = ft_atoi(arr[i]);
	i = -1;
	while (++i < 3)
		if (rgb[i] < 0 || rgb[i] > 255)
			exit_game(2, g);
	g->image->floor = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	pars_color_c(char **arr, t_game *g)
{
	int	i;
	int	rgb[3];

	i = -1;
	while (++i < 3 && arr[i])
		rgb[i] = ft_atoi(arr[i]);
	i = -1;
	while (++i < 3)
		if (rgb[i] < 0 || rgb[i] > 255)
			exit_game(2, g);
	g->image->sky = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}