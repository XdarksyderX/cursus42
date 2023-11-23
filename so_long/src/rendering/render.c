#include "../../inc/rendering.h"

static bool	ft_has_changed(char **map1, char **map2, int x, int y)
{
	return (map1[y][x] != map2[y][x]);
}

void	ft_render_sprite(t_data *data, int x, int y)
{
	void	*current_sprite;

	current_sprite = NULL;
	if (data->map->map[y][x] == '0')
		current_sprite = data->textures[0];
	else if (data->map->map[y][x] == '1')
		current_sprite = data->textures[1];
	else if (data->map->map[y][x] == 'C')
		current_sprite = data->textures[3];
	else if (data->map->map[y][x] == 'E')
		current_sprite = data->textures[2];
	else if (data->map->map[y][x] == 'P')
		current_sprite = data->textures[4];
	if (current_sprite != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			current_sprite, x * 50, y * 50);
}

void	ft_render_map(t_data *data, t_map *old_map)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (old_map == NULL
				|| ft_has_changed(data->map->map, old_map->map, x, y))
				ft_render_sprite(data, x, y);
			x++;
		}
		y++;
	}
}
