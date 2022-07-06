/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:18:47 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 13:59:38 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n / 16 > 0)
		len += ft_memlen(n / 16);
	len++;
	return (len);
}
