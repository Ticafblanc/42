/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_check_limit_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 06:03:49 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/13 06:03:52 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_check_limit_int(long long stk)
{
	if (stk < INT_MIN || stk > INT_MAX)
	{
		return (0);
	}
	return (1);
}
