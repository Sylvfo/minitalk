/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:41:55 by sforster          #+#    #+#             */
/*   Updated: 2024/03/20 15:13:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*joinchar(char *str, char c)
{
	char	*tmp;
	int		i;

	if (!str)
		str = malloc(2 * sizeof(char));
	if (!c)
		return (str);
	tmp = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	i++;
	tmp[i] = '\0';
	return (tmp);
}

void	get_message(int sig)
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
		message = joinchar(message, i);
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