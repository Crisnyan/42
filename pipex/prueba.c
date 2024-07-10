/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:31:08 by cristian          #+#    #+#             */
/*   Updated: 2024/07/04 18:10:28 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int	fds[2];
	char	*const args[1] = {"hola que tal"}; 
	
	fds[0] = STDIN_FILENO;
	fds[1] = STDOUT_FILENO;
	pipe(fds);
	pid = fork();
	if (pid == 0)
		execve("/bin/echo", args, envp);
		dup2(fds[1], STDOUT_FILENO);
}
