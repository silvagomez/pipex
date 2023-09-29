
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Two process to the power of n time fork() is called.
 * 2^n of process.
 * In this example there will 16 prints.
 */

int	main(int ac, char *ag[])
{
	(void)ac;
	(void)ag;
	printf("There will be 16 I\n");
	fork();
	fork();
	fork();
	fork();
	printf("I\n");
}
