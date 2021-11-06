/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 07:08:39 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/18 07:08:57 by mdoquocb         ###   ########.fr       */
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
	while (argc[0][i] != '\0')
	{
		ft_putchar(argc[0][i]);
		i++;
	}
	ft_putchar('\n');
}
