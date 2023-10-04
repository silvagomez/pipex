#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * The fork() in C.
 *
 * With fork() a child process gets born.
 * There will be two process.
 * All process has an id process.
 * fork() return an interger: id process.
 * The id child process always is zero.
 */
int	main(int ac, char *ag[])
{
	int	id;

	(void)ac;
	(void)ag;
	id = fork();
	printf("This text will be printed twice id: %d\n", id);
	if (id == 0)
		printf("Hello from child process\n");
	else
		printf("Hello from main process\n");
	return (0);
}
