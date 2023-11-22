#include "../inc/map.h"
#include "../inc/rendering.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_error("Invalid number of arguments");
	data = ft_init_data(argv[1]);
	if (!data)
		ft_error("Data initialization failed");
	ft_render_map(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
