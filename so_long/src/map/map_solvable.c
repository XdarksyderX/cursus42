#include "../../inc/map.h"

static bool	is_valid_move(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->width && y >= 0
		&& y < map->height && map->map[y][x] != '1');
}

static bool	dfs(t_map *map, int x, int y, int *collectibles)
{
	char	original;

	if (!is_valid_move(map, x, y) || map->map[y][x] == 'V')
		return (false);
	if (map->map[y][x] == 'C')
		(*collectibles)--;
	if (map->map[y][x] == 'E' && *collectibles == 0)
		return (true);
	original = map->map[y][x];
	map->map[y][x] = 'V';
	if (dfs(map, x + 1, y, collectibles)
		|| dfs(map, x - 1, y, collectibles)
		|| dfs(map, x, y + 1, collectibles)
		|| dfs(map, x, y - 1, collectibles))
		return (true);
	map->map[y][x] = original;
	return (false);
}

bool	ft_can_collect_all_and_exit(t_map *map)
{
	int	collectibles;
	int	player_cords[2];

	if (!find_player(map, player_cords))
		return (false);
	collectibles = map->max_collectives;
	return (dfs(map, player_cords[0], player_cords[1], &collectibles));
}
