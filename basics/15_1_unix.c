#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

/*
 * How to use FIFO files to communicae between process in C.
 *
 * To test this, create a fifo in the terminal.
 */
int	main(int ac, char *ag[])
{
	int arr[5];
	int	i;
	int	fd;

	(void)ac;
	(void)ag;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
		arr[i] = rand() % 100;
	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (1);
	for (i = 0; i < 5; i++)
	{
		if (write(fd, &arr[i], sizeof(int)) == -1 )
			return (2);
		printf("Wrote %d\n", arr[i]);
	}
	close(fd);
	return (0);
}
