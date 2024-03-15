/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prfrye_ex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:41:52 by sforster          #+#    #+#             */
/*   Updated: 2024/03/15 17:16:20 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
// sys/signal.h??
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	cleanup(int sigNUM)
{
	printf("Caught the signal number %d\n", sigNUM);
	printf("Doing program clean-up and exiting... \n\n");
	exit(-1);
}

int	main(int argc, char *argv[])
{
	struct sigaction sigact; //signal action structure

	//zero memory for sigact struct
	memset((void *)&sigact, 0, sizeof(sigact));

	// set values for signal action structure
	sigact.sa_handler = cleanup; // set signal handler function
	sigemptyset(&(sigact.sa_mask)); // set signals to block during execution to empty set

	// set signal handler for specified signal
	if (sigaction(SIGINT, &sigact, NULL))
	{
		perror("Error with sigaction: ");
		return -1;
	} //end if sigaction

	printf("Beginning program...\n");
	sleep(30); //sleep to allow for signal
	printf("No signals; ending program. \n\n");
	return (0);
} // end function main