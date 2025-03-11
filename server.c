/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:12 by skarras           #+#    #+#             */
/*   Updated: 2025/03/11 11:53:50 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	miniserver(void)
{
	while(1)
	{
		sigaction();
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Pid: %i\n", pid);

	return (0);
}
