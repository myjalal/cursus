/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:41:43 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/30 17:17:01 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void			param_init(t_frame *param, void *mlx, void *win)
{
	param->mlx = mlx;
	param->win = win;
	param->x = 250;
	param->y = 250;
}


int main(int argc, char **agrv)
{
	t_map	map;
	t_mlx	mlx;
	int		w; //width
	int		h; //hight
	char	*file;
	
	file = argv[1];
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	param_init(param, mlx_prt, win_ptr);
	
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, key_print, (void *)0);
	mlx_loop(mlx_ptr);	
	
}
