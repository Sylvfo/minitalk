/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:44:22 by sforster          #+#    #+#             */
/*   Updated: 2024/03/18 15:46:09 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

void send_message(int pid, char c)
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
		usleep(100); // pourquoi Ca?
	}
}
int main(int argc, char **argv)
{
	int	pid_int;
	int	i;

	if (argc !3 || ft_atoi(argv[i]) < 1)
	{
		printf("Enter valid arguments please. \n");
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

/*
Explications

send message. 

char c c'est une lettre du message. 
il faut transformer le char c ascii en bit => par exemple 'a' = 0110 0001

SIGUSR1 c'est le signal qu'on peut envoyer qui vaut 1
SIGUSR2 c'est le signal qu'on peut envoyer qui vaut 0

il faut donc prendre le 0110 0001 en l envoyer bit par bit
c-est dans la fonction send_message


<< 
fait avancer les chiffres de droites a gauche
shift = 0
c << shift = 0110 0001
shift = 1
c << shift = 1100 0010
shift = 2
c << shift = 1000 0100
shift = 3 
c << shift = 0000 1000
etc... jusqu a ce que ce que shift = 7

128
fait ca en bits 1000 0000

&
on compare comme ca: 
1 & 1 = 1 
1 & 0 = 0
0 & 0 = 0

|
on compare comme ca:
1 | 1 = 1
1 | 0 = 1
0 | 0 = 0

on va toujours comparere le premier chiffre de c avec 128

Donc shift 0
0110 0001
1000 0000

0 & 1 = 0
donc la condition marche pas donc on envoie SIGUSR2 (0) au serveur

ensuite shift 1
1100 0010
1000 0000
1 & 1 = 1
la condtion marche donc don envoie SIGUSR1 (1) au serveur

etc....

au final ca permet de decouper a = 0110 0001 pour envoyer 0-1-1-0-0-0-0-1

-----------------

fonction main:

int	pid_int;
	int	i;

//pas le bon nombre d'arguments
	if (argc !3 || ft_atoi(argv[i]) < 1)
	{
		printf("Enter valid arguments please. \n");
		return (0);
	}
	i = 0;
//argv[1] pid = pe le numero qu'on donne manellement apres qu il soit donne par le serveur. mais attention c-est un string
donc il faut le transformer avec atoi 	
	pid_int = ft_atoi(argv[1]);

boucle sur le message pour envoyer lettre par lettre dans la fonction send message qui l enverra bit par bit
	while (argv[2][i])
	{
		send_message(pid_int, argv[2][i]);
		i++;
	}
message de fin
	send_message(pid_int, '\0');
	return (0);
}

pid = pe le numero qu'on donne manellement. mais attention c-est un string
donc il faut le transformer avec atoi

*/