/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:48:13 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/05 16:10:04 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	cmd = ft_strjoin("/", cmd);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, X_OK) == 0)
		{
			free(cmd);
			ft_free_pp(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free(cmd);
	ft_free_pp(paths);
	return (NULL);
}

void	ft_execve(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (*cmd[0] == '/' || *cmd[0] == '.' || *cmd[0] == '~')
		path = cmd[0];
	else
		path = find_path(cmd[0], envp);
	execve(path, cmd, envp);
	ft_free_pp(cmd);
	free(path);
	ft_exit_perror("command not found", 127);
}

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		ft_exit_perror("Pipe child_process", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_exit_perror("Fork child_process", EXIT_FAILURE);
	if (pid > 0)
	{
		close(fd[FD_WRITE]);
		dup2(fd[FD_READ], STDIN_FILENO);
		close(fd[FD_READ]);
		waitpid(pid, &status, WNOHANG);
	}
	else
	{
		close(fd[FD_READ]);
		dup2(fd[FD_WRITE], STDOUT_FILENO);
		close(fd[FD_WRITE]);
		ft_execve(argv, envp);
	}
}
