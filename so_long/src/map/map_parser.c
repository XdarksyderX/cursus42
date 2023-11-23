#include "../../inc/map.h"
#include "../../inc/helpers.h"

static int	*ft_get_map_size(int fd)
{
	int		*map_size;
	char	*line;
	int		line_length;

	map_size = malloc(sizeof(int) * 2);
	if (!map_size)
		return (NULL);
	map_size[0] = 0;
	map_size[1] = 0;
	line = get_next_line(fd);
	map_size[0] = ft_strlen_protected(line);
	while (line)
	{
		map_size[1]++;
		line_length = ft_strlen_protected(line);
		if (line_length != map_size[0])
		{
			free(line);
			free(map_size);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (map_size);
}

static t_map	*ft_init_map(int *map_size)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map || !map_size)
		return (NULL);
	map->width = map_size[0];
	map->height = map_size[1];
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		map->map[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->map[i])
			return (ft_free_map(map));
		i++;
	}
	map->map[map->height] = NULL;
	return (map);
}

static t_map	*ft_fill_map(int fd, int *map_size)
{
	t_map	*map;
	char	*line;
	int		i;

	map = ft_init_map(map_size);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line && i < map->height)
	{
		ft_strlcpy(map->map[i], line, map->width + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	while (i < map->height)
	{
		map->map[i] = NULL;
		i++;
	}
	return (map);
}

static t_map	*ft_update_map_details(t_map *map)
{
	int	i;
	int	j;

	map->max_collectives = 0;
	map->collected = 0;
	map->exit_cords[0] = -1;
	map->exit_cords[1] = -1;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				map->max_collectives++;
			else if (map->map[i][j] == 'E')
			{
				map->exit_cords[0] = j;
				map->exit_cords[1] = i;
			}
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*ft_get_map(char *path)
{
	int		*map_size;
	t_map	*map;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_size = ft_get_map_size(fd);
	close(fd);
	if (!map_size)
		return (NULL);

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(map_size);
		return (NULL);
	}
	map = ft_fill_map(fd, map_size);
	free(map_size);
	close(fd);
	return (ft_update_map_details(map));
}
