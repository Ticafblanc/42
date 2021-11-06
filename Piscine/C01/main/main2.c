/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:32:22 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/09 09:11:17 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_swap(int *a, int *b);

int	main(void)
{
	int	c;
	int	d;

	c = 0;
	d = 1;
	printf("avant swap a = %d et b = %d\n", c, d);
	ft_swap(&c, &d);
	printf("apres swap a = %d et b = %d\n", c, d);
	return (0);
}
