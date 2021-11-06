/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:49:31 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/24 08:49:52 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	a;

	i = 0;
	a = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * a);
	while (min < max)
	{
		range[0][i] = min;
		i++;
		min++;
	}
	return (a);
}
