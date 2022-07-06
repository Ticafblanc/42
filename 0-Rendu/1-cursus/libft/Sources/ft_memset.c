/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 06:01:42 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/09/27 06:16:38 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	while (len-- > 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}
