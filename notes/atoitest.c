/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoitest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:14:03 by marvin            #+#    #+#             */
/*   Updated: 2024/03/20 16:14:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	main(int argc, char **argv)
{
	int	pid_int;
	int	i;

	if (argc != 3 || ft_atoi(argv[1]) < 1)
	{
		printf("Enter valid arguments please. \n");
		return (0);
	}
	pid_int = ft_atoi(argv[1]);
	printf ("%i", pid_int);
	return (0);
}