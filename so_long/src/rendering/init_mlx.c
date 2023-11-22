#include "../../inc/map.h"
#include "../../inc/rendering.h"

static t_data	*ft_add_sprites_data(t_data *data)
{
	int			width;
	int			height;
	int			i;
	const char	*texture_paths[NUM_TEXTURES]
		= {GROUND, WALL, EXIT, COLLECTIBLE, PLAYER};

	i = 0;
	while (i < NUM_TEXTURES)
	{
		data->textures[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				(char *) texture_paths[i], &width, &height);
		if (!data->textures[i])
			return (ft_cleanup_sprites(data, i));
		i++;
	}
	return (data);
}

t_data	*ft_init_data(char	*map_file)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	data->map = ft_get_map(map_file);
	if (!data->map)
		return (ft_free_data(data));
	if (!data->mlx_ptr)
		return (ft_free_data(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->width * 40,
			data->map->height * 40, "so_long");
	if (!data->win_ptr)
		return (ft_free_data(data));
	return (ft_add_sprites_data(data));
}

