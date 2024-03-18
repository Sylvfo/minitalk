/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_pid_sleep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:24 by sforster          #+#    #+#             */
/*   Updated: 2024/03/18 15:45:56 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("%i", pid);
	sleep(5);
	printf("%i", pid);
	sleep(5);
	printf("%i", pid);
}
/*
	while (1)
	{
		printf("%i", pid);
		sleep(10);
	}*/