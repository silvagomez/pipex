
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*
 * Communicating between process using pipe().
 *
 * How to data to other process, use pipe();
 * pipe(int fildes[2]); fildes integers are the files descriptor, key for access
 * read oor write.
 * fd[0] - read.
 * fd[1] - write.
 * fd are inherited.
 */
int	main(int ac, char *ag[])
{
	int fd[2];
	int	id;

	(void)ac;
	(void)ag;
	if (pipe(fd) == -1)
	{
		printf("An error ocurred with opening the pipe\n");
		return (1);
	}
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int	x;
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}
