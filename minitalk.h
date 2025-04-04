/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:30:14 by skarras           #+#    #+#             */
/*   Updated: 2025/03/19 11:28:16 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./Custom_Libft/libft.h"
# include <signal.h>

void	handler(int sig, siginfo_t *info, void *vp);
void	send(int pid, char a);
void	_kill(int pid, int signal);
void	miniclient(int pid, char *message);
void	build_message(char c);
char	*msgjoin(char *str, const char letter);
void	miniserver(void);

#endif
