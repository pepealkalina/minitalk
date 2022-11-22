/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:13 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/22 13:00:56 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_send_binary(const char c, int pid)
{
	int	shift;

	shift = -1;
	while (++shift < 8)
	{
		if (c & 0x80 >> shift)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(3);
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
	int	i;

	i = 0;
	while (i++ <= ft_strlen(argv[2]))
		ft_send_binary(argv[2][i], ft_connect_server(argv[1], argc));
	return (0);
}
