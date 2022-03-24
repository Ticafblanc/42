/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_make_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:25:46 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 13:35:03 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_make_lst(int argc, char **argv, t_mem *save)
{
	int			i;
	int			trigger;
	long long	l;

	i = 1;
	if (argc == 2)
		i = 0;
	trigger = 0;
	while (i < save->index_a)
	{
		l = ft_atol(argv[i]);
		if (trigger == 0)
		{
			save->l_lst_a = ft_lst_new((long long *)l);
			trigger = 1;
		}
		else
			ft_lst_add(save->l_lst_a, ft_lst_new((long long *)l));
		i++;
	}
	if (argc == 2)
		ft_free_pp(argv);
	if (ft_check_int(argc, save) == 0)
		return (0);
	return (1);
}

int	ft_check_int(int argc, t_mem *save)
{
	int	i;

	i = 0;
	if (argc > 2)
		save->index_a--;
	while (i < save->index_a)
	{
		if (ft_check_limit_int((long long)save->l_lst_a->content) == 0)
			return (0);
		if (ft_lst_check_double(save->l_lst_a->content,
				save->l_lst_a, save->index_a - i) == 0)
			return (0);
		save->l_lst_a = save->l_lst_a->next;
		i++;
	}
	return (1);
}
