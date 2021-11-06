/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 07:08:39 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/18 08:03:23 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	main(int argv, char **argc)
{
	int	i;

	i = 0;
	while (argv != 1)
	{
		while (argc[argv - 1][i] != '\0')
		{
			ft_putchar(argc[argv - 1][i]);
			i++;
		}
		i = 0;
		argv--;
		ft_putchar('\n');
	}
}
