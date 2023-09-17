
#include "../../include/ft_printf.h"

#include <stdint.h> // Para uintptr_t

int	ft_pointer_handler(void *ptr)
{
	ft_putpointer_fd(ptr, 1);
	return ( (int) (ft_ceil((ft_count_nbr_chars((unsigned long) ptr)/1.2041))) + 2);
}
