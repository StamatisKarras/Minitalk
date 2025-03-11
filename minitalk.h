/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:30:14 by skarras           #+#    #+#             */
/*   Updated: 2025/03/11 11:48:40 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "./Custom_Libft/libft.h"
#include <signal.h>

void	send(char *pid, char a);
void	_kill(char *pid, int signal);
void	miniclient(char *pid, char *message);

#endif
