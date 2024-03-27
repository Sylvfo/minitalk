/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:37:32 by sforster          #+#    #+#             */
/*   Updated: 2024/03/20 17:56:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(void)
{
	char	*st = "adf";
	char	s = 't';

	printf("%s", joinchar(st, s));
	return (0);
}
