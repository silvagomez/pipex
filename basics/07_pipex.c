#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 */
int	main(int ac, char *ag[])
{
	int id;
	int	result;

	(void)ac;
	(void)ag;
	id = fork();
	if (id == 0)
		sleep(1);
	printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
	result = wait(NULL);
	if (result == -1)
		printf("No children to wait for\n");
	else
		printf("%d finished et xecution\n", result);
	return (0);
}
