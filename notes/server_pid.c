/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:24 by sforster          #+#    #+#             */
/*   Updated: 2024/03/20 17:56:38 by marvin           ###   ########.fr       */
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
	return (0);
}
