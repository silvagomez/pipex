#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * wait() function.
 * What wait does is stop the execution until a child process has finished
 * executing.
 * wait() return a pid_t
 * We can only wait() in the main process because is the one that has child,
 * wait for the the child finish his execution.
 */
int	main(int ac, char *ag[])
{
	int id;
	int	n;
	int	idx;

	(void)ac;
	(void)ag;
	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(0);
	idx = n;
	for (idx = n; idx < n + 5; idx++)
	{
		printf("%d ", idx);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
}
