/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:22:01 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 14:04:08 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_str_len(char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}
