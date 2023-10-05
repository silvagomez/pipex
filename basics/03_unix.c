#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Waiting for processes to finish using wait() in C.
 *
 * The memory is copied:
 * Each process has a copy of its own variables, when is forked process get the
 * same values.
 * The memory place where they are allocated is different.
 *
 * The main process 6 7 8 9 10
 * The child proccess 1 2 3 4 5
 *
 * Unpredictable the system decides what is the order of the processes.
 * Output 1:
 * 6 1 7 2 8 3 9 4 10 5
 * Output 2:
 * 6 7 8 9 10
 * 1 2 3 4 5
 */
int	main(int ac, char *ag[])
{
	int	id;
	int	n;
	int	idx;

	(void)ac;
	(void)ag;
	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	idx = n;
	for (idx = n; idx < n + 5; idx++)
	{
		printf("%d ", idx);
		fflush(stdout);
	}
	printf("\n");
}
