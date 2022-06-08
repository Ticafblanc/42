/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:51:37 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/05/05 12:03:24 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* pipe ends */
# define FD_READ 0
# define FD_WRITE 1

/* libraries */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <libft.h>

typedef struct save_mem
{	
	int	infile;
	int	outfile;

}		t_mem;
/* 0_main.c */
void		here_doc(char *limiter, int argc);
int			open_file(int argc, char **argv, t_mem *save);

/* 1_utils.c */
char		*find_path(char *cmd, char **envp);
void		ft_execve(char *argv, char **envp);
void		child_process(char *argv, char **envp);

#endif
