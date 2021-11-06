/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:31:06 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/09 10:31:20 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_ultimate_div_mod(int	*a, int	*b);

int	main(void)
{
	int	a;
	int	b;

	a = 8;
	b = 4;
	printf("avant division a = %d et b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("apres division a = %d et b = %d\n", a, b);
	return (0);
}
