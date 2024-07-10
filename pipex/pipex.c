/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:19:50 by cristian          #+#    #+#             */
/*   Updated: 2024/07/05 17:24:48 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/ft_split.c"
#include "libft/ft_substr.c"
#include "libft/ft_strlen.c"
#include "libft/ft_strdup.c"
#include "pipex.h"
#include <sys/wait.h>

int	check_access(int argc, char **argv)
{
	int	i;

	i = 1;
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		return (-1);
	while (++i < argc - 1)
		//if ((access(argv[i], F_OK) == -1) 
		//	|| (access(argv[i], X_OK) == -1))
		//	return (-1);
	if (i == argc - 1)
		if (access(argv[i], F_OK) == -1 || access(argv[i], W_OK) == -1)
			return (-1);
	return (0);
}

int	dup_f1(char *file_1)
{
	int	old_fd;
	int	new_fd;

	old_fd = open(file_1, O_RDONLY);
	new_fd = dup2(old_fd, STDIN_FILENO);
	close(old_fd);
	return (new_fd);
}
char	*trijoin(char *s1, char *s2, char *s3)
{
	char	*str;
	int		i;

	str = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1);
	if ((s1 == NULL || s2 == NULL || s3 == NULL))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	while (*s3)
		str[i++] = *s3++;
	str[i] ='\0';
	return (str);
}

void	free_path(char **path_routes)
{
	int	i;

	i = -1;
	while (path_routes[++i])
		free(path_routes[i]);
	free(path_routes);
}

char	*get_path(char *name, char **envp)
{
	char	*path;
	char	**path_routes;
	int		i;
	i = -1;

	while (name[++i])
		if (name[i] == '/')
			return (name);
	i = -1;
	//search where path is
	while (envp[++i] != NULL)
		if (strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	//the path routes are divided with :
	path_routes = ft_split(envp[i], ':');
	path = NULL;
	i = -1;
	while (path_routes[++i])
	{
		path = trijoin(path_routes[i], "/", name);
		printf("path %d:%s\n", i, path);
		//if path exists and can be executed break
		if (path != NULL && access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			printf("path %d:%s\n", i, path);
			break ;
		}
		else
		{
			free(path);
			path = NULL;
		}
	}
	printf("fin\n");
	free_path(path_routes);
	printf("final path returned is: %s\n", path);
	return(path);
}

void	exec_program(int num, char **argv, char **envp)
{
	pid_t		pid;
	char		**cmd;
	const char	*path;
	int			fds[2];
	int			i;
	
	cmd = ft_split(argv[num], ' ');
	i = -1;
	while (cmd[++i])
		printf("cmd %i : %s\n", i, cmd[i]);
	printf("end of args\n");
	path = (const char *)get_path(cmd[0], envp);
	if (path == NULL)
		return (free_path(cmd), (void)perror("path is null"));
	printf("path is : %s\n", path);
	if (pipe(fds) == -1)
		return (free_path(cmd), (void)perror("pipe failed"));
	printf("read end: %d\n", fds[0]);
	printf("write end: %d\n", fds[1]);
	pid = fork();
	if (pid == -1)
		return (free_path(cmd), (void)perror("fork failed"));
	if (pid == 0)
	{
		printf("hello world from child -> %d\n", pid);
		close(fds[0]);
		if (dup2(fds[1], STDOUT_FILENO) == -1)
		{
			perror("dup2 failed");
			free_path(cmd);	
			close(fds[0]);
			exit(EXIT_FAILURE);
		}
		printf("read end from pid %d: %d\n", pid, fds[0]);
		printf("write end from pid %d: %d\n", pid, fds[1]);
		for (i = 1; cmd[i]; i++)
			printf("arg %d is: %s\n", i, cmd[i]);
		execve(path, cmd, envp); 
		perror("execve failed");
		free_path(cmd);	
		close(fds[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("hello world from parent -> %d\n", pid);
		wait(NULL);
		printf("write end from pid %d: %d\n", pid, fds[1]);
		close(fds[1]);
		if (dup2(fds[0], STDIN_FILENO) == -1)
			return (free_path(cmd), (void)perror("dup2 failed"));
		printf("read end from pid %d: %d\n", pid, fds[0]);
		close(fds[0]);
		free_path(cmd);	
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd;
	int	i;

	if (argc < 4)
	//if (argc < 5)
		exit(printf("Incorrect number of arguments\n"));
	if (check_access(argc, argv) == -1)
	{
		perror("check_access");
		exit(1);
	}
	printf("bien hecho!\n");
	fd = dup_f1(argv[1]);
	printf("fd: %d\n", fd);
	i = 1;
	while (++i < argc - 1)
		exec_program(i, argv, envp);
	//redir_to_f2();

}
