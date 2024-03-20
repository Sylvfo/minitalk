/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:48:06 by marvin            #+#    #+#             */
/*   Updated: 2024/03/20 15:48:06 by marvin           ###   ########.fr       */
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
	i = 0;
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
	static int	letter;
	static int	bits;
	static char	*message;

	if (sig == 1)
		letter = letter | 1;
	bits++;
	if (bits == 8)
	{
		if (letter == 0)
		{
			printf("%i\n", letter);
			message = NULL;
		}
		message = joinchar(message, letter);
		letter = 0;
		bits = 0;
	}
	letter = letter << 1;
}

int	main(void)
{
	get_message(01100001);
	get_message(1);
	get_message(1);
	get_message(0);

	get_message(0);
	get_message(0);
	get_message(0);
	get_message(1);
	return (0);
}