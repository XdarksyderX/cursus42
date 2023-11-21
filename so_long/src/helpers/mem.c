#include "../../inc/map.h"
#include "../../inc/helpers.h"

void	ft_free_map(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->map)
		{
			while (i < map->height)
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		free(map);
	}
}

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
