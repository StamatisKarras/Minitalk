/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:30:10 by skarras           #+#    #+#             */
/*   Updated: 2025/03/11 11:24:39 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(char *pid, char a)
{
	int	j;
	int	mask;

	j = 0;
	mask = 0b10000000;
	while (j != 8)
	{
		if ((a & mask) == 1)
			_kill(pid, SIGUSR1);
		else
			_kill(pid, SIGUSR2);
		mask >>= 1;
		j++;
		pause();
	}
}

void	_kill(char *pid, int signal)
{
	int	i;

	if (signal == 1)
	{
		i = kill(pid, SIGUSR1);
		if (i == -1)
		{
			write(-1, "Failed to send a signal", 12);
			exit(-1);
		}
	}
	else if(signal == 0)
	{
		i = kill(pid, SIGUSR2);
		if (i == -1)
		{
			write(-1, "Failed to send a signal", 12);
			exit(-1);
		}
	}
}

void	miniclient(char *pid, char *message)
{
	int	i;

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
		miniclient(argv[1], argv[2]);
	else
		ft_printf("Only a PID and a message is required");
}
