/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_get_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:54:47 by sforster          #+#    #+#             */
/*   Updated: 2024/03/15 17:16:29 by sforster         ###   ########.fr       */
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