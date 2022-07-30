#include "so_long.h"

static void	*init_img_util(t_mlx *mlx, char *filename)
{
	void	*result;
	int		width;
	int		height;

	width = 0;
	height = 0;
	result = mlx_xpm_file_to_image(mlx->mlx, filename, &width, &height);
	if (height == 0 || width == 0)
	{
		perror("img");
		exit (EXIT_FAILURE);
	}
	return (result);
}

static void	init_img(t_mlx *mlx, t_img *img)
{
	img->player = init_img_util(mlx, "img/player1.xpm");
	img->collect = init_img_util(mlx, "img/collect1.xpm");
	img->road = init_img_util(mlx, "img/road.xpm");
	img->wall = init_img_util(mlx, "img/wall.xpm");
	img->exit = init_img_util(mlx, "img/exit.xpm");
}

static int	program_close(void)
{
	write(1, "\033[0;34mExit program!\033[0\n", 24);
	exit(EXIT_SUCCESS);
}

void	so_long(char *filename)
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;
	int		width;
	int		height;

	parsing_map(&map, filename);
	mlx.mlx = mlx_init();
	width = map.width * 32;
	height = map.height * 32;
	mlx.win = mlx_new_window(mlx.mlx, width, height, "so_long");
	init_img(&mlx, &img);
	paint_map(&mlx, &map, &img);
	map.mlx = mlx;
	map.img = img;
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, X_NO_EVENT_MASK, &key_press, &map);
	mlx_hook(\
	mlx.win, X_EVENT_DESTROY_NOTIFY, X_NO_EVENT_MASK, &program_close, NULL);
	mlx_loop(mlx.mlx);
	mlx_clear_window(mlx.mlx, mlx.win);
}
