#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

/*
 * Introduction to FIFOs in C.
 *
 * In this case is diferent from 13_pipex because not need to wait... 
 * The key is open the fifo file for read and write O_RDWR.
 */
int	main(int ac, char *ag[])
{
	int fd;
	int	x;

	(void)ac;
	(void)ag;
	if (mkfifo("my_fifo_1", 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("Could not create filo file\n");
			return (1);
		}
	}
	printf("Opening...\n");
	fd = open("my_fifo_1", O_RDWR);
	printf("Opened.\n");
	x = 42;
	if (write(fd, &x, sizeof(x)) == -1)
		return (2);
	printf("Written.\n");
	close(fd);
	printf("Closed.\n");
	return (0);
}
