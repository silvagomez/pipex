
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * The fork() in C.
 *
 * This case create only 3 process.
 * 3 hello will be printed.
 */
int	main(int ac, char *ag[])
{
	int	id;

	(void)ac;
	(void)ag;
	id = fork();
	if (id != 0)
		fork();
	printf("Hello\n");
	return (0);
}
