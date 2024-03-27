/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:41:55 by sforster          #+#    #+#             */
/*   Updated: 2024/03/20 17:56:27 by marvin           ###   ########.fr       */
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
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	i = 0;
	tmp = malloc((ft_strlen(str) + 2) * sizeof(char));
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
	free (str);
	return (tmp);
}

void	get_message(int sig)
{
	static int	letter;
	static int	nb_bits;
	static char	*message;

	if (sig == SIGUSR1)
		letter = letter | 1;
	nb_bits++;
	if (nb_bits == 8)
	{
		if (letter == 0)
		{
			printf("%s\n", message);
			message = NULL;
		}
		message = joinchar(message, letter);
		letter = 0;
		nb_bits = 0;
	}
	letter = letter << 1;
}

int	main(void)
{
	printf("Hello my pid is %i \n", getpid());
	while (1)
	{
		signal(SIGUSR1, get_message);
		signal(SIGUSR2, get_message);
		pause();
	}
	return (0);
}
