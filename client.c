/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:44:22 by sforster          #+#    #+#             */
/*   Updated: 2024/03/27 11:51:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		else if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	result = result * minus;
	return (result);
}

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
	pid_int = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_message(pid_int, argv[2][i]);
		i++;
	}
	send_message(pid_int, '\0');
	return (0);
}
