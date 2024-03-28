/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_notes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:44:22 by sforster          #+#    #+#             */
/*   Updated: 2024/03/28 14:00:16 by sforster         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid_int;
	int	i;
	// waits so the signals won't get ignored
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