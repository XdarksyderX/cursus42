
#include "../../include/ft_printf.h"

int	ft_pointer_handler(void *ptr)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd((unsigned long long) ptr, "0123456789abcdef", 1);
	return ( (int) (ft_ceil((ft_count_nbr_chars((unsigned long long) ptr)/1.2041))) + 2);
}