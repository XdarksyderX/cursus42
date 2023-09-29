#include "../include/minitalk.h"

void	ft_send_char(pid_t pid, char c)
{
	int	bit_counter;
	int	bit_mask;

	bit_counter = sizeof(unsigned char) * 8 - 1;
	while (bit_counter >= 0)
	{
		bit_mask = 1 << bit_counter;
		if (c & bit_mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_counter--;
		usleep(100);
	}
}

void	ft_send_string(pid_t pid, char *str)
{
	while (*str)
	{
		ft_send_char(pid, *str++);
		usleep(100);
	}
}

int	main(int argc, char	**argv)
{
	pid_t	server_pid;

	if (argc != 3)
		ft_handle_error("Usage: ./minitalk <PID> \"message\"\n");
	server_pid = ft_atoi(argv[1]);
	ft_send_string(server_pid, argv[2]);
	ft_send_char(server_pid, '\n');
}
