
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*
 * Communicating between process using pipe().
 *
 * fd are inherited.
 * We need to close 4 times in this case because we have 4.
 *
 * Check and protect from errors.
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
	if (id == -1)
	{
		printf("Error ocurred with fork\n");
		return (4);
	}
	if (id == 0)
	{
		close(fd[0]);
		int	x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("Error ocurred with writing to pipe\n");
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int))  == -1)
		{
			printf("Error oocuurred with reading from the pipe\n");
			return (3);
		}
		close(fd[0]);
		y = y * 3;
		printf("Got from child process %d\n", y);
	}
	return (0);
}
