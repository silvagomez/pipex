#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * In this case id == 0 (child), child wait 1 second with sleep.
 * The parent process will terminate the process.
 * The parent id of the child won't be the parent id, because the parent process
 * dies before the child could execute.
 * So the child is runnig and a new parent proecess is assigned by the system,
 * this is known as ZOMBIE process because is you try to kill it, it's not going
 * to free the memory okay. Memory will not freed = memory leak.
 *
 * So functions that use the fork function, wait for the child processes to
 * finish before you termiante the main process.
 */
int	main(int ac, char *ag[])
{
	int id;

	(void)ac;
	(void)ag;
	id = fork();
	if (id == 0)
		sleep(1);
	printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
	//if (id != 0)
	//	wait(NULL);
	return (0);
}
