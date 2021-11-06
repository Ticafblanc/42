/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:36:31 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/09 09:36:47 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 8;
	b = 4;
	c = 0;
	d = 0;
	ft_div_mod(a, b, &c, &d);
	printf("%d div %d = %d\n", a, b, c);
	printf("%d mod %d = %d\n", a, b, d);
	return (0);
}
