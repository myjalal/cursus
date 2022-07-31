/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:41:43 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/31 19:22:34 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>



/*int	key_print(int key, t_mlx *mlx)
{
	if (key == UP)
	{
		if (mlx->h >= 10)
			mlx->h = mlx->h - 10;
	}
	else if (key == DOWN)
	{
		if (mlx->h <= 490)
			mlx->h = mlx->h + 10;
	}
	else if (key == LEFT)
	{
		if (mlx->w >= 10)
			mlx->w = mlx->w - 10;
	}
	else if (key == RIGHT)
	{
		if (mlx->w <= 490)
			mlx->w = mlx->w + 10;
	}
	else if (key == ESC)
		exit (0);
	ft_printf("h = %d, w = %d\n", mlx->h, mlx->w);
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->w, mlx->h, 0xFFFFFF);
	return (0);
}*/


int main(int argc, char **argv)
{
/*	t_map	map;
	t_mlx	mlx;
	t_img	img;
	int		i = 200; //width*/
	int		i ; //hight
	char	*file;

	file = argv[1];
	if (argc < 2)
	{
		ft_printf("No arguments found\n");
		exit(EXIT_FAILURE);
	}
	
	i = ft_strlen(file) - 4;
	if (ft_strcmp(".ber", &file[i]))
		printf("ERROR\n");
	else
		ft_printf("No errors, %s", &file[i]);
	
	//ft_printf("\n%d\n",ft_strlen(argv[1]));
	//map_checker (argv[1]);
	/*mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "so_long");
	//ft_printf("h = %d, w = %d\n", mlx.h, mlx.w);
	//mlx_key_hook(mlx.win, key_print, &mlx);
	while (i <= mlx.h)
	{
		j = 200;
		while (j <= mlx.w)
			mlx_pixel_put(mlx.mlx, mlx.win, j++, i, 0xFFFFFF);
		++i;
	}
	//mlx_pixel_put(mlx.mlx, mlx.win, 250, 250, 0xFFFFFF);
	
	mlx_loop(mlx.mlx);	*/
	
	return (0);
}
