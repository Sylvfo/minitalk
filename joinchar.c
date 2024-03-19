/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:37:32 by sforster          #+#    #+#             */
/*   Updated: 2024/03/19 13:50:16 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	strlen(char *str)
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

	if (!str)
		str = malloc(2 * sizeof(char));
	tmp = malloc((strlen(str) + 1)) * sizeof(char));
	
	
}
