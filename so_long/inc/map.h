#ifndef MAP_H
# define MAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include "../libs/libft/libft.h"

typedef struct s_map
{
	unsigned char	**map;
	int				width;
	int				height;
}	t_map;

char	*get_next_line(int fd);

#endif