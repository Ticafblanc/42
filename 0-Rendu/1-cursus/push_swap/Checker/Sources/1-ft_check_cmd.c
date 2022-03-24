/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_check_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/23 17:20:55 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_check_cmd(char *cmd)
{
	int	n;

	n = 1;
	n *= ft_case_0(cmd);
	if (n == 0)
		return (0);
	n *= ft_case_1(cmd);
	if (n == 0)
		return (0);
	n *= ft_case_2(cmd);
	if (n == 0)
		return (0);
	if (cmd[2] == '\n' || cmd[3] == '\n')
		return (n);
	return (0);
}

int	ft_case_0(char *cmd)
{
	if (cmd[0] == 'p')
		return (10);
	if (cmd[0] == 's')
		return (20);
	if (cmd[0] == 'r')
		return (40);
	return (0);
}

int	ft_case_1(char *cmd)
{
	if (cmd[1] == 's')
		return (20);
	if (cmd[1] == 'r')
		return (40);
	if (cmd[1] == 'a')
		return (2);
	if (cmd[1] == 'b')
		return (3);
	return (0);
}

int	ft_case_2(char *cmd)
{
	if (cmd[2] == 'r')
		return (40);
	if (cmd[2] == 'a')
		return (2);
	if (cmd[2] == 'b')
		return (3);
	if (cmd[2] == '\n')
		return (1);
	return (0);
}
