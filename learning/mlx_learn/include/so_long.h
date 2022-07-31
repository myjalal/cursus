/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:16:37 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/31 19:04:15 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*****LIBRARIES*****/
# include "../libft/incs/libft.h"
# include "../mlx/mlx.h"

# include <fcntl.h> // open
# include <stdio.h> // perror

/*****BUFFER_SIZE*****/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#  define MLX_ERROR 1
# endif

/*****STRUCTURES*****/
#define ESC		53
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*road;
	void	*coin;
	void	*exit;
}	t_img;

typedef struct s_map
{
	t_mlx	mlx;
	t_img	img;
	char	**map;
	int		w;
	int		h;
	int		x;
	int		y;
}	t_map;

void	map_checker(char *file);

#endif

