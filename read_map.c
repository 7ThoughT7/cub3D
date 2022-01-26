/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:40:19 by bmohamme          #+#    #+#             */
/*   Updated: 2021/12/04 15:12:06 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int		search_max_str(t_game *g)
{
	int y;
	int x;
	int max_x;

	y = 0;
	max_x = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
			x++;
		if (x > max_x)
			max_x = x;
		y++;
	}
	return (max_x);
}

void	filling_map_max_str(t_game *g)
{
	int		y;
	int 	x;

	y = 0;
	g->len_x = search_max_str(g);
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
			x++;
		x = g->len_x - x;
		while (x > 0)
		{
			g->map[y] = ft_strjoin(g->map[y], " ");
			x--;
		}
		y++;
	}

//	int i = 0;
//	while (g->map[i])
//	{
//		printf("map - |%s|\n", g->map[i]);
//		i++;
//	}
}

void	write_map(int fd, t_game *g)
{
	int 	y;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line))
	{
		g->map[y++] = ft_strdup(line);
		free(line);
	}
	g->map[y] = ft_strdup(line);
	free(line);
	g->map[y + 1] = NULL;
	g->len_y = y + 1;
}

void	read_map(int fd, t_game *g, int num_str, char **av)
{
	char	*line;
	int 	i;

	i = 2;
	while (get_next_line(fd, &line))
	{
		free(line);
		i++;
	}
	free(line);
	close(fd);
	g->map = (char **) malloc(sizeof(char *) * (i + 1));
	fd = open(av[1], O_RDONLY);
	while (num_str-- > 0)
	{
		get_next_line(fd, &line);
		free(line);
	}
	write_map(fd, g);
}