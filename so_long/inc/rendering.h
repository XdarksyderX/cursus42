#ifndef RENDERING_H
# define RENDERING_H

# include "map.h"
# include "helpers.h"
# include "../libs/mlx/mlx.h"

# define GROUND "assets/grass.xpm"
# define WALL "assets/water.xpm"
# define EXIT "assets/nest.xpm"
# define COLLECTIBLE "assets/egg.xpm"
# define PLAYER "assets/chicken.xpm"

# define NUM_TEXTURES 5

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	t_map		*map;
}	t_data;

t_data	*ft_init_data(char	*map_file);
void	ft_render_map(t_data *data);

#endif