#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include "libft/ft_split.c"
#include "libft/ft_substr.c"
#include "libft/ft_strlen.c"
#include "libft/ft_strdup.c"
#include "pipex.h"

// Function to check file access permissions
int check_access(int argc, char **argv) {
    if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
        return -1;
    if (access(argv[argc - 1], F_OK) != -1 && access(argv[argc - 1], W_OK) == -1)
        return -1;
    return 0;
}

// Function to open input file and duplicate file descriptor
int dup_f1(char *file_1) {
    int old_fd = open(file_1, O_RDONLY);
    if (old_fd == -1) {
        perror("open input file failed");
        exit(EXIT_FAILURE);
    }
    int new_fd = dup2(old_fd, STDIN_FILENO);
    close(old_fd);
    return new_fd;
}

// Function to join three strings
char *trijoin(char *s1, char *s2, char *s3) {
    char *str = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1);
    if (str == NULL)
        return NULL;
    strcpy(str, s1);
    strcat(str, s2);
    strcat(str, s3);
    return str;
}

// Function to free memory allocated for path routes
void free_path(char **path_routes) {
    int i = 0;
    while (path_routes[i])
        free(path_routes[i++]);
    free(path_routes);
}

// Function to get the full path of a command
char *get_path(char *name, char **envp) {
    char *path;
    char **path_routes;
    int i = -1;

    while (name[++i])
        if (name[i] == '/')
            return name;

    i = -1;
    while (envp[++i] != NULL)
        if (strncmp(envp[i], "PATH=", 5) == 0)
            break;

    path_routes = ft_split(envp[i] + 5, ':');
    if (path_routes == NULL)
        return NULL;

    i = -1;
    while (path_routes[++i]) {
        path = trijoin(path_routes[i], "/", name);
        if (path != NULL && access(path, F_OK) == 0 && access(path, X_OK) == 0)
            break;
        else {
            free(path);
            path = NULL;
        }
    }
    free_path(path_routes);
    return path;
}

// Function to execute a program
void exec_program(int num, char **argv, char **envp, int fd_in, int fd_out) {
    pid_t pid;
    char **cmd;
    const char *path;

    cmd = ft_split(argv[num], ' ');
    path = get_path(cmd[0], envp);
    if (path == NULL) {
        free_path(cmd);
        perror("path is null");
        return;
    }

    pid = fork();
    if (pid == -1) {
        free_path(cmd);
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        if (dup2(fd_in, STDIN_FILENO) == -1 || dup2(fd_out, STDOUT_FILENO) == -1) {
            perror("dup2 failed");
            free_path(cmd);
            exit(EXIT_FAILURE);
        }
        execve(path, cmd, envp);
        perror("execve failed");
        free_path(cmd);
        exit(EXIT_FAILURE);
    } else {
        close(fd_in);
        close(fd_out);
        wait(NULL);
        free_path(cmd);
    }
}

int main(int argc, char **argv, char **envp) {
    int fd_in, fd_out;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <command1> <command2> ... <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (check_access(argc, argv) == -1) {
        perror("check_access");
        exit(EXIT_FAILURE);
    }

    fd_in = dup_f1(argv[1]);

    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    exec_program(2, argv, envp, fd_in, pipe_fds[1]);

    close(pipe_fds[1]);
    fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
        perror("open output file failed");
        exit(EXIT_FAILURE);
    }

    exec_program(3, argv, envp, pipe_fds[0], fd_out);

    return 0;
}

