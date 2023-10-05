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
 * mkfifo("my_fifo_1", 0777), this create a file with 777 permission
 * open() return a file descriptor.
 *
 * Opening the read or write end of FIFO blocks until other end is also opened
 * (by another process or thread).
 * 
 * Executing this will stay in Opening... due to need that other process read
 * my_filo_1 for end the before process that is opening.
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
	fd = open("my_fifo_1", O_WRONLY);
	printf("Opened.\n");
	x = 42;
	if (write(fd, &x, sizeof(x)) == -1)
		return (2);
	printf("Written.\n");
	close(fd);
	printf("Closed.\n");
	return (0);
}
