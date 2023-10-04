
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*
 * Calling fork mulltiple times.
 *
 * id_1 = x
 * id_2 = z
 *	⬇︎				⬇︎
 *	x→	id_1 = 0	z→	id_1 = x
 *		id_2 = y		id_2 = 0
 *	⬇︎
 *	y→	id_1 = 0
 *		id_2 = 0
 *
 * wait(NULL) returns -1 if there is nothing for wait for.
 * To protect from ZOMBIE process:
 * while (wait(NULL) != -1 || errno != ECHILD)
 */
int	main(int ac, char *ag[])
{
	int id_1;
	int id_2;

	(void)ac;
	(void)ag;
	id_1 = fork();
	id_2 = fork();
	if (id_1 == 0)
	{
		if (id_2 == 0) //child of a child?
			printf("We are process y\n");
		else
			printf("We are process x\n");
	}
	else
	{
		if (id_2 == 0)
			printf("We are process z\n");
		else
			printf("We are the parent process \n");

	}
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for child to finish\n");
		//printf("Waited for child to finish");
	return (0);
}
