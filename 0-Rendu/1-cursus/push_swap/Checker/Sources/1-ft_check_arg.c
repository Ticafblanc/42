/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-ft_check_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:28:48 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 09:37:54 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	**ft_check_arg(int argc, char **argv, t_mem *save)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
		return (ft_is_string_arg(argc, argv, save));
	else
		return (ft_is_multi_arg(argc, argv, save));
}

char	**ft_is_string_arg(int argc, char **argv, t_mem *save)
{
	argv = ft_split(argv[1], ' ');
	return (ft_is_multi_arg(argc, argv, save));
}

char	**ft_is_multi_arg(int argc, char **argv, t_mem *save)
{
	save->index_a = ft_is_nbr(argc, argv);
	if (save->index_a == 0)
	{
		if (argc == 2)
			ft_free_pp(argv);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (save->index_a == -1)
	{
		if (argc == 2)
			ft_free_pp(argv);
		return (0);
	}
	return (argv);
}

int	ft_is_nbr(int argc, char **argv)
{
	int	i;
	int	i2;

	i = 0;
	if (argc == 2)
		i = -1;
	if (!argv[i + 1])
		return (-1);
	i2 = 0;
	while (argv[++i])
	{
		while (argv[i][i2] != '\0')
		{
			if (argv[i][i2] == '-' && i2 == 0)
				i2++;
			if (ft_isdigit(argv[i][i2]))
				i2++;
			else
				return (0);
		}
		if (i2 > 11)
			return (0);
		i2 = 0;
	}
	return (i);
}
