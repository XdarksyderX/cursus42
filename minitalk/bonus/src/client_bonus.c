#include "../include/minitalk_bonus.h"

struct s_string_data
{
	char	*string_to_send;
	int		lst_rec_char;
} string_data;

void	ft_sign_handler(int signum, siginfo_t *info, void	*context)
{
	(void) context;
	if (signum == SIGUSR1)
	{
		ft_printf("[%i] Character %c received\n", info->si_pid,
			string_data.string_to_send[string_data.lst_rec_char]);
		string_data.lst_rec_char++;
	}
}

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
	ft_send_char(pid, '\0');
}

int	main(int argc, char	**argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		ft_handle_error("Usage: ./minitalk <PID> \"message\"\n");
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sign_handler;
	string_data.string_to_send = argv[2];
	string_data.lst_rec_char = 0;
	server_pid = ft_atoi(argv[1]);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_handle_error("Error while configuring signals");
	ft_send_string(server_pid, string_data.string_to_send);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
