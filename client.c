/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:39 by sforster          #+#    #+#             */
/*   Updated: 2024/03/15 17:16:34 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

/*
from cursus gitbook

Write a program (main) in which the client takes two parameters/arguments
The PID of the server to which it wants to send the message
A message
Encrypt the message (I did the encryption via bits)
Send the message to the server (via its PID)
Create a stop condition so that the server knows when it has finished receiving the message
*/



pause until recieved pid. 

binary 100 = end of transmission.

encrypte message 

send message to serveur. 

stop. 

int main(int argc, int pid, char *str)
{
	int	i;
	int j;
	int	bit;or char *bit?

	i = 0
	while(str[i])
	{
		transformer char en bit

		while(bit[j])
		{
			if bit[j] = 0
				kill(server_pid, SIGUSR1);
			if bit[j] = 0
				kill(server_pid, SIGUSR2);
		}
	if str[i] = '/0';
		free
		finishs
}

