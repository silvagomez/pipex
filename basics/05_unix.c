#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * Process IDs in C.
 *
 * Every single process in unix has id, is unique.
 * THe output will be:
 * CHILD => Child id, main/parent id.
 * PARENT => Main/parent id, parent of the main process.
 * Every process in the system has a parent process id.
 */
int	main(int ac, char *ag[])
{
	int id;

	(void)ac;
	(void)ag;
	id = fork();
	printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
	return (0);
}
