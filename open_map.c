/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:01:25 by bmohamme          #+#    #+#             */
/*   Updated: 2021/12/04 18:59:11 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pars_image(char *line, t_game *g)
{
	int 	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	if (line[0] == 'N' && line[1] == 'O')
		g->image->no = ft_strdup(&line[i]);
	else if (line[0] == 'S' && line[1] == 'O')
		g->image->so = ft_strdup(&line[i]);
	else if (line[0] == 'W' && line[1] == 'E')
		g->image->we = ft_strdup(&line[i]);
	else if (line[0] == 'E' && line[1] == 'A')
		g->image->ea = ft_strdup(&line[i]);
}

void	pars_color(char *line, t_game *g)
{
	int	i;
	char	**arr;

	i = 1;
	while (line[i] == ' ')
		i++;
	arr = ft_split(&line[i], ',');
	if (line[0] == 'F')
		pars_color_f(arr, g);
	else if (line[0] == 'C')
		pars_color_c(arr, g);
	free_arr(arr);
}

int	check_p(char *line, t_game *g)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) ||
		!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
	{
		pars_image(line, g);
		return (1);
	}
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
	{
		pars_color(line, g);
		return (1);
	}
	return (0);
}

int	read_param(int fd, t_game *g)
{
	int		i;
	int		num_str;
	char	*line;

	i = 6;
	num_str = 0;
	while (i > 0 && get_next_line(fd, &line))
	{
		if (check_p(line, g))
			i--;
		num_str++;
		free(line);
	}
	while (get_next_line(fd, &line) && !ft_strncmp(line, "", 1))
	{
		free(line);
		num_str++;
	}
	free(line);
	return (num_str);
}

void	open_map(t_game *g, char **av)
{
	int		fd;
	int 	num_str;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_game(1, g);
	num_str = read_param(fd, g);
	check_valid_param(g);
	read_map(fd, g, num_str, av);
	filling_map_max_str(g);
	check_valid_map(g);
	check_valid_symbol(g);
	close(fd);
}
