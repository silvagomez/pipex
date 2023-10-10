/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:27 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/10/09 15:59:07 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incude "pipex.h"

/*
 * execve(const char *path, char *const argv[], char *const envp[]);
 */
int	main(int ac, char *av[])
{
	int fd[2];
	int pid;

	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
