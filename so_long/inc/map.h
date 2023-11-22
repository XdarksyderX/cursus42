#ifndef MAP_H
# define MAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdbool.h>

# include "../libs/libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		max_collectives;
	int		player_position[2];
}	t_map;

char	*get_next_line(int fd);
bool	ft_validate_map(t_map *map);
t_map	*ft_get_map(char *path);

#endif