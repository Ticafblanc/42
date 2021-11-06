/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:54:05 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/08 11:54:36 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_numbers(void)
{
	char	x;

	x = '0';
	while (x <= '9')
	{
		write(1, &x, 1);
		x = x + 1;
	}
}
