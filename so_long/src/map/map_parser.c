#include "../../inc/map.h"
#include "../../inc/helpers.h"

static t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	return (map);
}

static int	ft_process_line(t_map *map, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (map->width == 0)
		map->width = len;
	else if (map->width != len)
		return (0);

	if (!ft_expand_map(map, len))
		return (0);
	map->map[map->height - 1] = ft_strdup(line);
	if (!map->map[map->height - 1])
		return (0);
	return (1);
}

static int	ft_expand_map(t_map *map, size_t len)
{
	char	**temp;

	temp = ft_realloc(map->map, map->height * sizeof(char *),
			(map->height + 1) * sizeof(char *));
	if (!temp)
		return (0);
	map->map = temp;
	map->height++;
	return (1);
}

t_map	*ft_get_map(int fd)
{
	t_map	*map;
	char	*line;

	map = ft_init_map();
	if (!map)
		return (NULL);

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_process_line(map, line))
		{
			ft_free_map(map);
			free(line);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

