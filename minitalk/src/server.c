#include "../include/minitalk.h"

//TODO: Change ft_printf with the working version

struct s_char_data
{
	unsigned char	received_data;
	unsigned int	received_bits;
	unsigned int	is_receiving;
} char_data;

void	ft_sign_handler(int signum)
{
	if (!char_data.is_receiving)
	{
		char_data.received_data = 0;
		char_data.received_bits = 0;
		char_data.is_receiving = 1;
	}
	char_data.received_data <<= 1;
	if (signum == SIGUSR1)
		char_data.received_data |= 1;
	char_data.received_bits++;
	if (char_data.received_bits == sizeof(char) * 8)
	{
		write(STDOUT_FILENO, &char_data.received_data, 1);
		char_data.is_receiving = 0;
	}
}


int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	if (pid == -1)
		ft_handle_error("Error on fetching the PID");
	char_data.is_receiving = 0;
	sa.sa_handler = ft_sign_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_handle_error("Error while configuring signals");
	ft_printf("PID: %i\n", pid);
	while (1)
		pause();
	return (0);
}
