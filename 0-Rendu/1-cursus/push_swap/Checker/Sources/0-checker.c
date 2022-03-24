/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:14:14 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/22 13:35:27 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_mem		save;

	save.l_lst_a = NULL;
	save.l_lst_b = NULL;
	save.index_a = 0;
	save.index_b = 0;
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
		ft_sorts_lst(&save);
	ft_free_l_lst(save.l_lst_a, save.index_a);
	ft_free_l_lst(save.l_lst_b, save.index_b);
	return (0);
}
