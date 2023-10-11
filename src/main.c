/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:27 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/10/11 16:17:06 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *  < file1 cmd1 | cmd2 > file2
 *  ./pipex infile "cmd_1" "cmd_2" outfile
 *  	0		1		2		3		4
 */
void	error_terminate(char *s)
{
	perror(s);
	exit(1);
}

/*
 */
/*
size_t	validate_argv(char *av[], char *env[])
{

}
*/
int	main(int ac, char *av[], char *env[])
{
	t_pipex	px;

	(void)av;
	if (ac != 5)
		error_terminate("Error, format required: infile 'cmd' 'cmd' outfile");
/*
	if (validate_argv(av, env) == 0)
		error_terminate("Invalid argument: ");
*/
	/*
	 * Test of execve();
	 * execve(const char *path, char *const argv[], char *const envp[]);
	 *
	 * px.cmd_1 = ft_split("ping -c 3 google.com", ' '); 
	 * if (execve("/sbin/ping", px.cmd_1, env) < 0)
	 * 		error_terminate("EXECVE CHILD: ");
	 */
	px.path_1 = "/sbin/ping";
	px.cmd_1 = ft_split("ping -c 3 google.com", ' ');
	px.path_2 = "/bin/cat";
	px.cmd_2 = ft_split("cat", ' ');
	if (pipe(px.p_fd) < 0)
		error_terminate("Error pipe(): ");
	px.pid = fork();
	if (px.pid < 0)
		error_terminate("Error fork(): ");
	if (px.pid == 0)
	{
		close(px.p_fd[0]);
		px.f_fd = open("infile", O_RDONLY, 0777);
		if (px.f_fd < 0)
			error_terminate("Error open() child: ");
		dup2(px.f_fd, STDIN_FILENO);
		dup2(px.p_fd[1], STDOUT_FILENO);
		close(px.p_fd[1]);
		// if command can not execute return error
		if (execve(px.path_1, px.cmd_1, env) < 0)
			error_terminate("Error execve() child: ");
	}
	else
	{
		wait(NULL);
		//close(px.p_fd[1]);
		px.f_fd = open("outfile", O_CREAT | O_TRUNC | O_RDWR, 0777);
		ft_printf("Parent process\n");
		if (px.f_fd < 0)
			error_terminate("Error open() parent: ");
		dup2(px.p_fd[0], STDIN_FILENO);
		dup2(px.f_fd, STDOUT_FILENO);
		ft_printf("INTRUSIVE TEXT!!!!!!\n");
		close(px.p_fd[0]);
		if (execve(px.path_2, px.cmd_2, env) < 0)
			error_terminate("Error execve() parent: ");
	}
	close(px.p_fd[0]);
	close(px.p_fd[1]);
	return (0);
}
