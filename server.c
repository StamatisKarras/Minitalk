/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:12 by skarras           #+#    #+#             */
/*   Updated: 2025/03/17 13:34:45 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	build_letter(int byte)
{
	static	int	count;

	if (count == 8)
	{
		ft_printf("%c\n", letter);
		build_message(letter);
		count = 0;
		letter = 0;
	}
	if (byte == 1 || byte == 0)
	{
		if (byte == 1)
		{
			letter = (letter << 1);
			letter = (letter | 1);
		}
		else if (byte == 0)
			letter = (letter << 1);
		count++;
	}
}

void	build_message(char c)
{
	static char	*message;

	if (message == NULL)
	{
		message = malloc(1);
		message[0] = '\0';
	}
	message = ft_strjoin(message, &c);
	ft_printf("%s\n", message);
	if (c == '\0')
	{
		ft_printf("%s\n", message);
		free(message);
		message = NULL;
	}
}

void	handler(int sig, siginfo_t *info, void *vp)
{
	(void) vp;
	(void) info;
	if (sig == SIGUSR1)
	{
		build_letter(1);
		kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		build_letter(0);
		kill(info->si_pid, SIGUSR1);
	}
}

void	miniserver()
{
	struct sigaction 	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while(1)
	{
		pause();
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Pid: %i\n", pid);
	miniserver();
	return (0);
}
