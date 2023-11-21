#ifndef HELPERS_H
# define HELPERS_H

# include "../libs/libft/libft.h"
# include "map.h"

void	ft_free_map(t_map *map);
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);

#endif