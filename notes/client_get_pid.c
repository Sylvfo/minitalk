/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_get_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:54:47 by sforster          #+#    #+#             */
/*   Updated: 2024/03/20 17:56:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, int argv)
{
	int pidrecu;

	if (argc == 2)
	{
		pidrecu = argv;
	}
	printf("%i", pidrecu)
}