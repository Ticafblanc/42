/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:37:41 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/10 00:21:20 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size)
{
	int	s;
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i != (size - 1))
	{
		while (c != (size - 1))
		{
			if (tab[c] > tab[c + 1])
			{
				s = tab[c];
				tab[c] = tab[c + 1];
				tab[c + 1] = s;
			}
			c++;
		}
		c = 0;
		i++;
	}
}
