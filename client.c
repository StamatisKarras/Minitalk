/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:30:10 by skarras           #+#    #+#             */
/*   Updated: 2025/03/20 14:25:48 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ready;

void	sig_handler(int sig)
{
	(void) sig;
	if (sig == SIGUSR1)
		g_ready = 1;
}

void	send(int pid, char a)
{
	int					j;
	int					mask;
	struct sigaction	action;
	struct sigaction	ignore;

	action.sa_handler = sig_handler;
	ignore.sa_handler = SIG_IGN;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGINT, &ignore, NULL);
	j = 0;
	mask = 0b10000000;
	while (j != 8)
	{
		if ((a & mask))
			_kill(pid, SIGUSR1);
		else
			_kill(pid, SIGUSR2);
		mask >>= 1;
		j++;
		while (g_ready == 0)
			usleep(1);
		g_ready = 0;
	}
}

void	_kill(int pid, int signal)
{
	int	i;

	if (signal == SIGUSR1)
	{
		i = kill(pid, SIGUSR1);
		if (i == -1)
		{
			write(2, "Failed to send a signal\n",
				ft_strlen("Failed to send a signal\n"));
			exit(-1);
		}
	}
	else if (signal == SIGUSR2)
	{
		i = kill(pid, SIGUSR2);
		if (i == -1)
		{
			write(2, "Failed to send a signal\n",
				ft_strlen("Failed to send a signal\n"));
			exit(-1);
		}
	}
}

void	miniclient(int pid, char *message)
{
	int	i;

	if (kill(pid, 0) == -1 || pid <= 0)
	{
		write(2, "Invalid PID\n", ft_strlen("Invalid PID\n"));
		exit(-1);
	}
	i = 0;
	while (message[i])
	{
		send(pid, message[i]);
		i++;
	}
	send(pid, '\0');
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		miniclient(ft_atoi(argv[1]), argv[2]);
	else
		ft_printf("A PID and a message is required\n");
}
