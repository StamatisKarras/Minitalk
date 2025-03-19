/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:12:17 by skarras           #+#    #+#             */
/*   Updated: 2025/03/19 11:12:51 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*msgjoin(char *str, const char letter)
{
	char	*new_message;
	size_t	len;
	int		i;

	len = ft_strlen(str) + 1;
	new_message = (char *) malloc((len + 1) * sizeof(char));
	if (!new_message)
	{
		ft_printf("Malloc Error");
		exit(-1);
	}
	i = 0;
	while (str[i])
	{
		new_message[i] = str[i];
		i++;
	}
	new_message[i++] = letter;
	new_message[i] = '\0';
	free(str);
	return (new_message);
}
