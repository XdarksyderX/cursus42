#include "../../inc/map.h"
#include "../../inc/rendering.h"
#include "../../inc/helpers.h"

void	*ft_free_map(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->map)
		{
			i = 0;
			while (i < map->height)
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		free(map);
	}
	return (NULL);
}

void	*ft_cleanup_sprites(t_data *data, int loaded)
{
	int	i;

	i = 0;
	while (i < loaded)
	{
		mlx_destroy_image(data->mlx_ptr, data->textures[i]);
		i++;
	}
	return (NULL);
}

void	*ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->map)
			ft_free_map(data->map);
		if (data->textures)
			ft_cleanup_sprites(data, NUM_TEXTURES);
		if (data->mlx_ptr)
		{
			if (data->win_ptr)
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		}
		free(data);
	}
	return (NULL);
}
