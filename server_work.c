/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:33:59 by sforster          #+#    #+#             */
/*   Updated: 2024/03/18 15:46:01 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

/*
from cursus gitbook
Display its PID
Create an endless loop so that the server can receive signals at any time
Receive signals
Decrypt signals
For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action
*/

/*
1 doit envoyer le pid
2 doit afficher le message
*/

/*
make file

my own printf
*/

getpid;

	display pid

	signal(SIGUSR1, )
	pause(); /*until received info from client.*/


	recevoir les signaux et les mettres par 8
	transformer les bits en char
	stocker les char dans *message.
	decrypte info

	malloc bit?
	transformer bit en char. 
s
	if bit = 0000 0000 fin du signal. 
		-> terminer

	

int main(int argc, SIGUSR1, SIGUSR2 )???
{
	char	*message;
	int		bytes;

	printf("%s", message);
	return (0);
}