/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_sorts_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/24 10:25:06 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_sorts_lst(t_mem *save)
{
	char	*cmd;
	int		i;

	cmd = get_next_line(0);
	while (cmd && cmd[0] != '\n')
	{
		i = ft_check_cmd(cmd);
		if (i == 0)
		{
			ft_free_l_lst(save->l_lst_a, save->index_a);
			ft_free_l_lst(save->l_lst_b, save->index_b);
			free(cmd);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		if (ft_sortss_lst(i, save) == 2)
			break ;
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
	ft_output(save);
}

void	ft_output(t_mem *save)
{
	if (ft_check_lst(save->l_lst_a, save->index_a) == 1
		&& save->l_lst_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return ;
}

int	ft_check_lst(t_struct *l_lst, int index)
{
	int	i;

	i = 0;
	while (i++ < index - 1)
	{
		if ((long long)l_lst->content
			> (long long)l_lst->next->content)
			return (0);
		l_lst = l_lst->next;
	}
	return (1);
}
