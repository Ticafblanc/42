/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:13:13 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/08 13:50:46 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char	a, char	b, char	c);

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putchar(a, b, c);
				if (!(a == '7' && b == '8' && c == '9'))
					write(1, ", ", 1);
				else
					return ;
				c++;
			}
			b++;
		}
		a++;
	}
}

void	ft_putchar(char a, char	b, char	c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}
