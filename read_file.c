/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:48:19 by bmohamme          #+#    #+#             */
/*   Updated: 2022/01/26 21:32:39 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_t_image(t_image *image)
{
	image->no = NULL;
	image->so = NULL;
	image->we = NULL;
	image->ea = NULL;
}

void	file_extension_check(char **av, t_game *g)
{
	int		fd;
	char	*dot;
	char	*cub;

	cub = ".cub";
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
		exit_game(1, g);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_game(1, g);
	dot = ft_strchr(av[1], '.');
	if (dot[0] == '\0')
		exit_game(1, g);
	if (ft_strncmp(dot, cub, 4) != 0)
		exit_game(1, g);
}

void read_file(t_main *main, char **av)
{
	main->game = malloc(sizeof(t_game));
	file_extension_check(av, main->game);
	main->game->image = malloc(sizeof(t_image));
	init_t_image(main->game->image);
	open_map(main->game, av);
	printf("NO - %s\n", main->game->image->no);
	printf("SO - %s\n", main->game->image->so);
	printf("WE - %s\n", main->game->image->we);
	printf("AE - %s\n", main->game->image->ea);
	printf("F - %lu\n", main->game->image->floor);
	printf("C - %lu\n", main->game->image->sky);
}