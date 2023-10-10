/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:27 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/10/10 19:36:44 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_terminate(char *s)
{
	perror(s);
	exit(1);
}

/*
 * execve(const char *path, char *const argv[], char *const envp[]);
 */
/*
size_t	validate_argv(char *av[], char *env[])
{

}
*/
int	main(int ac, char *av[], char *env[])
{
	t_pipex	px;

	if (ac != 5)
		error_terminate("Error, required format: < file1 cmd1 | cmd2 > file2");
/*
	if (validate_argv(av, env) == 0)
		error_terminate("Invalid argument: ");
*/
	if (pipe(px.fd) < 0)
		error_terminate("Pipe: ");
	px.pid = fork();
	if (px.pid < 0)
		error_terminate("Fork: ");
	if (px.pid == 0)
	{
		close(px.fd[0]);
		px.file = open("infile", O_RDONLY);
		if (px.file < 0)
			error_terminate("Open: ");
		dup2(px.file, STDOUT_FILENO);
		execve("/usr/bin/grep", av, env);
		close(px.fd[1]);
	}
	else
	{
		wait(NULL);
		ft_printf("Success\n");
	}
	return (0);
}
