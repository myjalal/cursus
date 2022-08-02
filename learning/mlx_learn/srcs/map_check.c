/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:51:16 by jechekao          #+#    #+#             */
/*   Updated: 2022/08/01 20:34:00 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	error(char *error)
{
	ft_printf("Error: %s\n", error);
	exit(MLX_ERROR);
}

// i may need to close and re-open
void	transcribe(t_map *map, char *file)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (i < map->h)
		map->map[i++] = get_next_line(fd);
	close(fd);
	print(map);
}

void	map_checker(t_map *map, char *file)
{
	int		fd;
	char	*temp;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		error("You are trying to open a dir.");
	fd = open(file, O_RDONLY);
	if (fd < 0 || ft_strfcmp(".ber", file, 4))
		error("Wrong file name or extention");
	temp = get_next_line(fd);
	map->h = 0;
	map->w = ft_strlen(temp);
	while (temp)
	{
		if (map->w != ft_strlen(temp))
			error("There is an error in your map, Please verify");
		free(temp);
		temp = get_next_line(fd);
		map->h++;
	}
	free(temp);
	map->map = (char **)malloc(sizeof(char *) * map->h);
	ft_printf("h = %d\n", map->h);
	close(fd);
	transcribe(map, file);
}
