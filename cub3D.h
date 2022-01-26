#ifndef CUB3D_H
#define CUB3D_H

#include "GNL/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_image
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	long	floor;
	long	sky;
}			t_image;

typedef struct s_game
{
	int		str_num;
	int		len_y;
	int 	len_x;
	int 	pers;
	char	vector;
	int 	pers_y;
	int 	pers_x;
	char	**map;
	t_image	*image;
}			t_game;

//read_file
void read_file(t_game *g, char **av);
void	file_extension_check(char **av, t_game *g);
void	init_t_image(t_image *image);

//addit_func_0
void	exit_game(int i, t_game *g);
void	free_arr(char **arr);
void	check_valid_param(t_game *g);
void	pars_color_f(char **arr, t_game *g);
void	pars_color_c(char **arr, t_game *g);

//addit_func_1
void	free_map(t_game *g);


//open_map
int		read_param(int fd, t_game *g);
void	open_map(t_game *game, char **argv);
int		check_p(char *line, t_game *g);
void	pars_color(char *line, t_game *g);
void	pars_image(char *line, t_game *g);

//lib_func
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *s);
int		ft_isdigit(int c);

//ft_split
char	**ft_split(char *s, char c);

//read_map
void	read_map(int fd, t_game *g, int num_str, char **av);
void	filling_map_max_str(t_game *g);
int		search_max_str(t_game *g);
void	write_map(int fd, t_game *g);

//check_map
void	check_valid_map(t_game *g);
void	perimeter_check(t_game *g);
void	check_valid_symbol(t_game *g);
void	check_pers(t_game *g, int y, int x);

#endif
