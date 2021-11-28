/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:37:41 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/09 21:37:58 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	s;
	int	i;

	size = size - 1;
	i = 0;
	while (size > i)
	{
		s = tab[size];
		tab[size] = tab[i];
		tab[i] = s;
		size--;
		i++;
	}
}
