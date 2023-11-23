#include "../../inc/controls.h"

void	get_movement_delta(int direction, int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (direction == UP)
		*dy = -1;
	else if (direction == DOWN)
		*dy = 1;
	else if (direction == LEFT)
		*dx = -1;
	else if (direction == RIGHT)
		*dx = 1;
}

static int	is_valid_move(t_data *data, int new_x, int new_y)
{
	char	next_cell;

	if (new_x >= 0 && new_x < data->map->width
		&& new_y >= 0 && new_y < data->map->height)
	{
		next_cell = data->map->map[new_y][new_x];
		return (next_cell != '1');
	}
	return (0);
}

static void	perform_move(t_data *data, int player_cords[2],
	int new_x, int new_y)
{
	char	next_cell;

	next_cell = data->map->map[new_y][new_x];
	if (next_cell == 'C')
		data->map->collected++;
	data->map->map[player_cords[1]][player_cords[0]] = '0';
	data->map->map[new_y][new_x] = 'P';
	data->movements++;
}

static t_map	*move_player(t_data *data, int player_cords[2], int dx, int dy)
{
	int		new_x;
	int		new_y;
	t_map	*old_map;

	old_map = ft_copy_map(data->map);
	if (!old_map)
		return (NULL);
	new_x = player_cords[0] + dx;
	new_y = player_cords[1] + dy;
	if (is_valid_move(data, new_x, new_y))
		perform_move(data, player_cords, new_x, new_y);
	ft_putnbr_fd(data->movements, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (old_map);
}

t_map	*ft_move_player(t_data *data, int direction)
{
	int	player_cords[2];
	int	dx;
	int	dy;

	if (!find_player(data->map, player_cords))
		return (NULL);
	get_movement_delta(direction, &dx, &dy);
	return (move_player(data, player_cords, dx, dy));
}
