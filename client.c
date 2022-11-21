/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:13 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/20 19:24:36 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_send_binary(const char *message, int pid)
{
	int	i;
	int	shift;

	shift = 0;
	i = 0;
	while (message[i])
	{
		while (shift++ < 8)
		{
			if (message[i] & 0x80 >> shift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
		}
		usleep(3);
		i++;
	}
}

int	ft_connect_server(char const *strpid, int argc)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid arguments");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(strpid);
	kill(pid, SIGUSR1);
	return (pid);
}

int	main(int argc, char const *argv[])
{
	ft_send_binary(argv[2], ft_connect_server(argv[1], argc));
	return (0);
}
