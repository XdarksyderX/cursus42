#ifndef RENDERING_H
# define RENDERING_H

# include "map.h"
# include "helpers.h"
# include "../libs/mlx/mlx.h"

# define GROUND "assets/ground.xpm"
# define WALL "assets/wall.xpm"
# define EXIT "assets/exit.xpm"
# define COLLECTABLE "assets/collectable.xpm"
# define PLAYER "assets/player.xpm"

# define NUM_TEXTURES 5

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	t_map		*map;
	int			movements;
}	t_data;

t_data	*ft_init_data(char	*map_file);

void	ft_render_map(t_data *data, t_map *old_map);
void	ft_render_sprite(t_data *data, int x, int y);

#endif