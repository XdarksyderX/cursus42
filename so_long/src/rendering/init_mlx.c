#include "../../inc/map.h"
#include "../../inc/rendering.h"
#include "../../inc/controls.h"

static t_data	*ft_add_sprites_data(t_data *data)
{
	int			width;
	int			height;
	int			i;
	const char	*texture_paths[NUM_TEXTURES]
		= {GROUND, WALL, EXIT, COLLECTABLE, PLAYER};

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

t_data	*ft_init_data(char *map_file)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = ft_get_map(map_file);
	if (!data->map)
		return (ft_error("Parsing error"));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_free_data(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->width * 50,
			data->map->height * 50, "so_long");
	if (!data->win_ptr)
		return (ft_free_data(data));
	data->movements = 0;
	mlx_key_hook(data->win_ptr, ft_handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, ft_handle_close, data);
	return (ft_add_sprites_data(data));
}
