/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:38:21 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/09 21:50:49 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	c[4];
	int	size;

	c[0] = 1;
	c[1] = 2;
	c[2] = 3;
	c[3] = 4;
	size = 4;
	printf("tab [1] %d tab [2] %d tab [3] %d tab [4] %d\n",
		   	c[0], c[1], c[2], c[3]);
	ft_rev_int_tab(c, size);
	printf("tab [1] %d tab [2] %d tab [3] %d tab [4] %d\n",
		   	c[0], c[1], c[2], c[3]);
	return (0);
}
