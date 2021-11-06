/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 07:08:39 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/18 07:49:20 by mdoquocb         ###   ########.fr       */
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
	int	v;

	v = 1;
	i = 0;
	while (argv != v)
	{
		while (argc[v][i] != '\0')
		{
			ft_putchar(argc[v][i]);
			i++;
		}
		i = 0;
		v++;
		ft_putchar('\n');
	}
}
