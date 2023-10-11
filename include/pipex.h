/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:35:08 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/10/11 16:13:11 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

// Allowed libraries
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		p_fd[2];
	int		f_fd;
	pid_t	pid;
	char	*env;
	char	*path_1;
	char	*path_2;
	char	**cmd_1;
	char	**cmd_2;
}				t_pipex;

#endif
