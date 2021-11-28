/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 06:57:51 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/09 07:56:34 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_ultimate_ft(int *********nbr);

void	ft_var(int	****p4)
{
	int	*****p5;
	int	******p6;
	int	*******p7;
	int	********p8;
	int	*********nbr;

	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	p8 = &p7;
	nbr = &p8;
	ft_ultimate_ft(nbr);
	printf("%d\n", *********nbr);
}

int	main(void)
{
	int	a;
	int	*p;
	int	**p2;
	int	***p3;
	int	****p4;

	a = 1;
	p = &a;
	p2 = &p;
	p3 = &p2;
	p4 = &p3;
	ft_var(p4);
	return (0);
}
