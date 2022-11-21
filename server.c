/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:20 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/20 19:24:37 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/*Handle the client signals*/

void	ft_signal_handler(int signum)
{
	static char		c;
	static int		bits;

	c = 0;
	bits = 0xFF;
	if (signum == SIGUSR1)
	{
		ft_printf("0");
		c ^= 0x80 >> bits;
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("1");
		c |= 0x80 >> bits;
	}
	bits++;
	if (bits == 8)
	{
		ft_printf("-> %c\n", c);
		bits = 0;
		c = 0xFF;
	}
}

/* Start the server process printing the PID
** and recieve the client signals*/

void	ft_connect_client(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (1)
		pause();
}

int	main(void)
{
	ft_connect_client();
	return (0);
}
