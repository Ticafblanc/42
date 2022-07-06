/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:23:47 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/01 09:50:34 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_puthex(unsigned int n, int cap)
{
	char	*set;
	int		printed;
	int		i;

	if (cap == 1)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	printed = 0;
	if (n / 16 > 0)
		printed += ft_puthex(n / 16, cap);
	i = n % 16;
	write(1, &set[i], 1);
	printed++;
	return (printed);
}
