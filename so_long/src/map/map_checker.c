#include "../../inc/map.h"

static bool	ft_check_map_shape(t_map *map)
{
	int	i;

	if (!map || map->width == 0 || map->height == 0)
		return (false);
	i = 0;
	while (i < map->height)
	{
		if (((int) ft_strlen(map->map[i])) != map->width)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_map_walls(t_map *map)
{
	ssize_t	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_player_and_exit(t_map *map)
{
	int	player_count;
	int	exit_count;
	int	i;
	int	j;

	player_count = 0;
	exit_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				player_count++;
			else if (map->map[i][j] == 'E')
				exit_count++;
			j++;
			if (player_count > 1 || exit_count > 1)
				return (false);
		}
		i++;
	}
	return (player_count == 1 && exit_count == 1);
}

static bool	ft_check_collectibles(t_map *map)
{
	int	collectible_count;
	int	i;
	int	j;

	collectible_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				collectible_count++;
			j++;
			if (!(map->map[i][j] == 'P' || map->map[i][j] == 'E'
				|| map->map[i][j] == '1'
					|| map->map[i][j] == '0' || map->map[i][j] == 'C'))
				return (false);
		}
		i++;
	}
	return (collectible_count >= 1);
}

bool	ft_validate_map(t_map *map)
{
	if (!ft_check_map_shape(map))
		return (false);
	if (!ft_check_map_walls(map))
		return (false);
	if (!ft_check_player_and_exit(map))
		return (false);
	if (!ft_check_collectibles(map))
		return (false);
	if (!ft_can_collect_all_and_exit(map))
		return (false);
	return (true);
}
