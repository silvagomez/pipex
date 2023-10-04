
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*
 * Practical use case for fork() and pipe() in C.
 */
int	main(int ac, char *ag[])
{
	int	arr[] = {1, 2, 3, 4, 1, 2};
	int	start;
	int	end;
	int	arr_size;
	int	fd[2];
	int id;
	int	sum;
	int i;
	
	(void)ac;
	(void)ag;
	// this give the numbers of integers in the array.
	arr_size = sizeof(arr) / sizeof(int);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = start + arr_size / 2;
	}
	else
	{
		start = arr_size / 2;
		end = arr_size;
	}
	sum = 0;
	for (i = start; i < end; i++)
		sum += arr[i];
	printf("Calculate partial sum: %d\n", sum);
	return (0);
}
