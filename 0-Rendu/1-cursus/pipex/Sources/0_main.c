/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:42:50 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/05 16:11:07 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	check_limiter(int fd, char *limiter)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			close(fd);
			free(line);
			return (1);
		}
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd);
	free(line);
	return (0);
}

void	here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		ft_exit_strerror(EINVAL, EXIT_FAILURE);
	if (pipe(fd) == -1)
		ft_exit_perror("Pipe here_doc", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_exit_perror("Fork here_doc", EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[FD_READ]);
		if (check_limiter(fd[FD_WRITE], limiter) == 1)
			exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[FD_WRITE]);
		dup2(fd[FD_READ], STDIN_FILENO);
		wait(NULL);
	}
}

int	open_file(int argc, char **argv, t_mem *save)
{
	int	i;

	save->outfile = 0;
	save->infile = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		save->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
		here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		save->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		save->infile = open(argv[1], O_RDONLY, 0777);
		dup2(save->infile, STDIN_FILENO);
		close(save->infile);
	}
	if (save->outfile == -1)
		ft_exit_perror(argv[argc -1], EXIT_FAILURE);
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	t_mem	save;
	int		i;

	if (argc >= 5)
	{
		i = open_file(argc, argv, &save);
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(save.outfile, STDOUT_FILENO);
		close(save.outfile);
		ft_execve(argv[argc - 2], envp);
	}
	ft_exit_strerror(EINVAL, EXIT_FAILURE);
}
