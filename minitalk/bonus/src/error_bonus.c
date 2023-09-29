#include "../include/minitalk_bonus.h"

void	ft_handle_error(char	*str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
