/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:14:14 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 13:22:03 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_mem		save;

	save.l_lst_a = NULL;
	save.l_lst_b = NULL;
	save.index_a = 0;
	save.index_b = 0;
	save.pos = 0;
	save.mv = 0;
	argv = ft_check_arg(argc, argv, &save);
	if (!argv)
		return (0);
	if (ft_make_lst(argc, argv, &save) == 0)
	{
		ft_free_l_lst(save.l_lst_a, save.index_a);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_check_lst(save.l_lst_a, save.index_a) == 0
		&& save.index_a > 1)
		ft_sort_lst(&save);
	ft_free_l_lst(save.l_lst_a, save.index_a);
	return (0);
}
