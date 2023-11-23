#include "../../inc/controls.h"

int	ft_handle_close(t_data *data)
{
	ft_free_data(data);
	exit(0);
	return (0);
}

void	ft_post_move_actions(t_data *data)
{
	int	player_cords[2];

	find_player(data->map, player_cords);
	if ((player_cords[0] == data->map->exit_cords[0]
			&& player_cords[1] == data->map->exit_cords[1])
		&& data->map->collected == data->map->max_collectives)
		ft_handle_close(data);
	if (player_cords[0] != data->map->exit_cords[0]
		|| player_cords[1] != data->map->exit_cords[1])
	{
		data->map->map[data->map->exit_cords[1]][data->map->exit_cords[0]]
			= 'E';
	}
	ft_render_sprite(data, data->map->exit_cords[0],
		data->map->exit_cords[1]);
}

int	ft_handle_keypress(int keycode, t_data *data)
{
	t_map	*old_map;

	old_map = NULL;
	if (keycode == 53 || keycode == 65307)
		ft_handle_close(data);
	else if (keycode == 119)
		old_map = ft_move_player(data, UP);
	else if (keycode == 115)
		old_map = ft_move_player(data, DOWN);
	else if (keycode == 97)
		old_map = ft_move_player(data, LEFT);
	else if (keycode == 100)
		old_map = ft_move_player(data, RIGHT);
	if (old_map)
		ft_render_map(data, old_map);
	ft_post_move_actions(data);
	ft_free_map(old_map);
	return (0);
}
