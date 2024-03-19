/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:41:55 by sforster          #+#    #+#             */
/*   Updated: 2024/03/19 13:50:23 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void get_message(int sig)
{
	static int	i;
	static int	letter;
	static char	*message;

//pas compris
	if (sig == SIGUSR1)
		i = i | 1;
	letter++;
	// letter = 8 ca veut dire qu on a une lettre
	if (letter == 8)
	{
		// quand i = 0 ca veut dire i = '\0' de la fin du message)
		if (i == 0)
		{
			printf("%s\n", message);
		// j imagine pour eviter les leaks
			message = NULL;
		}
		message = join_char(message, i);
		i = 0;
		letter = 0;
	}
// incrementation
	i = i << 1;
}

int main(void)
{
// donne le pid
	printf("Hello my pid is %i \n", getpid());
	return (0);
	while(1)
	{
		signal(SIGUSR1, get_message);
		signal(SIGUSR2, get_message);
		pause();
	}
	return (0);
}