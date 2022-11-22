/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:20 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/22 12:53:52 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/*Handle the client signals*/
/* ^ -> compare two bits if they are the same = 1, else = 0*/
/* | -> compare two bits if one of them is 1 then = 1, else = 0*/

void	ft_signal_handler(int signum)
{
	static char		c = 0xFF;
	static int		bits = 0;

	if (signum == SIGUSR1)
	{
		c ^= 128 >> bits;
	}
	else if (signum == SIGUSR2)
	{
		c |= 128 >> bits;
	}
	if (++bits == 8)
	{
		ft_printf("%i\n", c);
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
