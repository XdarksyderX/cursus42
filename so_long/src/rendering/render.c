#include "../../inc/rendering.h"

void	ft_render_map(t_data *data)
{
	int		x;
	int		y;
	void	*current_sprite;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
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
					current_sprite, x * 15, y * 15);
			x++;
		}
		y++;
	}
}
