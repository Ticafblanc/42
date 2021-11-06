/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 07:08:39 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/18 08:48:44 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	main(int argv, char **argc)
{
	char	c[];
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (c != (argv - 1))
	{
		if (argc[c] < argv[c + 1])
		{
			s = tab[c];
			tab[c] = tab[c + 1];
			tab[c + 1] = s;
		}
		c++;
	}
	c = 0;
	i++;
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

