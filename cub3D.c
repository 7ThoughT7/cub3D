/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmohamme <bmohamme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:48:26 by bmohamme          #+#    #+#             */
/*   Updated: 2021/12/03 19:49:25 by bmohamme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

void	my_put_pixel(t_win *win, float x, float y, int color)
{
	char	*dst;

	dst = win->addr + (((int)y + SIZE_DIF_PIX) * win->line_l + ((int)x + SIZE_DIF_PIX) * (win->b_p_p / 8));
	*(unsigned int*)dst = color;
}

void	paint_rect(t_win *win, int x, int y, int color)
{
	int	i;
	int j;

	i = -1;
	while (++i < SIZE_DIF_PIX)
	{
		j = -1;
		while (++j < SIZE_DIF_PIX)
			my_put_pixel(win, (float)(x + j), (float)(y + i), color);
	}
}

//void	paint_fov(t_win *win, t_player *pers)
//{
//	int		i;
//	int 	j;
//	int 	fov_len;
//	unsigned int	*dst;
//	float	cur_fov;
//
//	fov_len = 0;
//	cur_fov = pers->start;
//	while (cur_fov <= pers->end)
//	{
//		i = (int)pers->y * SIZE_DIF_PIX;
//		j = (int)pers->x * SIZE_DIF_PIX;
//		dst = win->addr + ((i + SIZE_DIF_PIX) * win->line_l + (j + SIZE_DIF_PIX) * (win->b_p_p / 8));
//		while (*dst) != COLOR_WALL)
//		{
//			if (*(unsigned int*)(dst) != COLOR_FOV)
//			{
//				my_put_pixel(win, (float)j, (float)i, COLOR_FOV);
//				fov_len++;
//				i = i - (int)((sinf(pers->way) * (float)fov_len));
//				j = j + (int)((cosf(pers->way) * (float)fov_len));
//			}
//			dst = win->addr + ((i + SIZE_DIF_PIX) * win->line_l + (j + SIZE_DIF_PIX) * (win->b_p_p / 8));
//			printf("1");
//		}
//		cur_fov = cur_fov - ((float)FOV)/REYS;
//	}
//}


void	paint_player(t_win *win, int j, int i)
{

	i = i * SIZE_DIF_PIX + SIZE_DIF_PIX / 2 + 1;
	j = j * SIZE_DIF_PIX + SIZE_DIF_PIX / 2 + 1;
	my_put_pixel(win, (float)j, (float)i, COLOR_PLYR);
//	if ((int)win->addr[j * win->line_l + i * (win->b_p_p / 8)] != COLOR_WALL)
//		my_put_pixel(win, (float)j, (float)i, COLOR_PLYR);
	j--;
	if ((int)win->addr[j * win->line_l + i * (win->b_p_p / 8)] != COLOR_WALL)
		my_put_pixel(win, (float)j, (float)i, COLOR_PLYR);
	j += 2;
	if ((int)win->addr[j * win->line_l + i * (win->b_p_p / 8)] != COLOR_WALL)
		my_put_pixel(win, (float)j, (float)i, COLOR_PLYR);
	j--;
	i--;
	if ((int)win->addr[j * win->line_l + i * (win->b_p_p / 8)] != COLOR_WALL)
		my_put_pixel(win, (float)j, (float)i, COLOR_PLYR);
	i +=2;
	if ((int)win->addr[j * win->line_l + i * (win->b_p_p / 8)] != COLOR_WALL)
		my_put_pixel(win, (float)j, (float)i, COLOR_PLYR);
}

//11111111111111111111111111111111111111
//11000011100001100001100001100001100001
//11000000000000000000000000000001000001
//100E00010000000000001000W0000001000011
//10000001000000111111100000000000000011
//11111111111111111111111111111111111111

void	minimap(t_win *win, t_player *pers, t_game *game)
{
	int i;
	int j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				paint_rect(win, j * SIZE_DIF_PIX, i * SIZE_DIF_PIX, COLOR_WALL);
			else if (game->map[i][j] == '0')
				paint_rect(win, j * SIZE_DIF_PIX, i * SIZE_DIF_PIX, (int)game->image->floor);
			else if (game->map[i][j] == ' ')
				paint_rect(win, j * SIZE_DIF_PIX, i * SIZE_DIF_PIX, COLOR_EMPTY);
		}
	}
	paint_player(win,(int)pers->x, (int)pers->y);
//	paint_fov(win, pers);
//	paint_rect(win, (int)pers->x * SIZE_DIF_PIX, (int)pers->y * SIZE_DIF_PIX, COLOR_PLYR);
}

void	init_pers(t_main *main)
{
	main->pers = malloc(sizeof(t_player));
	main->pers->x = (float)main->game->pers_x;
	main->pers->y = (float)main->game->pers_y;
	if (main->game->vector == 'E')
		main->pers->way = (float)0;
	else if (main->game->vector == 'N')
		main->pers->way = (float)90;
	else if (main->game->vector == 'W')
		main->pers->way = (float)180;
	else if (main->game->vector == 'S')
		main->pers->way = (float)270;
	main->pers->start = main->pers->way - (float)FOV/2;
	main->pers->end = main->pers->way + (float)FOV/2;
}

int main(int ac, char **av)
{
	t_main	main;

	if (ac != 2)
	{
		printf("Invalid param\n");
		exit (1);
	}
	main.win = malloc(sizeof(t_win));
	main.win->mlx = mlx_init();
	main.win->win = mlx_new_window(main.win->mlx, WIN_X, WIN_Y, "RUN");
	main.win->img = mlx_new_image(main.win->mlx, WIN_X, WIN_Y);
	main.win->addr = mlx_get_data_addr(main.win->img, &main.win->b_p_p, &main.win->line_l, &main.win->endian);
	read_file(&main, av);
	init_pers(&main);
	minimap(main.win, main.pers, main.game);
	mlx_put_image_to_window(main.win->mlx, main.win->win, main.win->img, 0, 0);
	mlx_loop(main.win->mlx);
	return (0);
}