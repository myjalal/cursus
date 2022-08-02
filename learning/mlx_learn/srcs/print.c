/*
	DELETE AFTER FINISHING
	DELETE AFTER FINISHING
	DELETE AFTER FINISHING
	*/

#include "so_long.h"

void	print(t_map *map)
{
	size_t		i;

	i = 0;
	while(i < map->h)
		ft_printf("%s\n", map->map[i++]);
}
