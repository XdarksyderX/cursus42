#ifndef CONTROLS_H
# define CONTROLS_H

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

# include "rendering.h"

int		ft_handle_keypress(int keycode, t_data *data);
int		ft_handle_close(t_data *data);

t_map	*ft_move_player(t_data *data, int direction);

#endif