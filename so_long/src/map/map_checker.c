#include "../../inc/map.h"

static int	ft_check_map_shape(t_map *map)
{
	int	i;

	if (!map || map->width == 0 || map->height == 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != map->width)
			return (0);
	}
	return (1);
}

