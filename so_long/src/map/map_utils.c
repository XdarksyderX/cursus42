#include "../../inc/map.h"

t_map	*ft_copy_map(t_map *map)
{
	t_map	*new_map;
	int		i;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->width = map->width;
	new_map->height = map->height;
	new_map->map = malloc(sizeof(char *) * (new_map->height + 1));
	if (!new_map->map)
		return (NULL);
	i = 0;
	while (i < new_map->height)
	{
		new_map->map[i] = ft_strdup(map->map[i]);
		if (!new_map->map[i])
			return (NULL);
		i++;
	}
	new_map->map[i] = NULL;
	return (new_map);
}

int	find_player(t_map *map, int player_cords[2])
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				player_cords[0] = x;
				player_cords[1] = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
