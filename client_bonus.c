/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:44:22 by sforster          #+#    #+#             */
/*   Updated: 2024/03/27 15:17:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "librairies/printf/ft_printf.h"
#include "librairies/libft/libft.h"

void	send_message(int pid, char c)
{
	int	shift;

	shift = 0;
	while (shift < 8)
	{
		if ((c << shift) & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		shift++;
		usleep(100);
	}
}
void	message_received(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message received");
}


int	main(int argc, char **argv)
{
	int	pid_int;
	int	i;

	if (argc != 3 || ft_atoi(argv[1]) < 1)
	{
		ft_printf("Enter pid and message please. \n");
		return (0);
	}
	i = 0;
	signal(SIGUSR1, message_received);
	pid_int = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_message(pid_int, argv[2][i]);
		i++;
	}
	send_message(pid_int, '\0');
	return (0);
}
