/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_app.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoqouocb@student.42quebec.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:30 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/01 09:15:14 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_printf_flag_app(int ft, int *flag)
{
	int	i;

	i = 0;
	if (ft == 1)
	{
		while (i++ < (*flag))
			write(1, " ", 1);
	}
	else if (ft == 2)
	{
		(*flag) = 1;
		write(1, "+", 1);
	}
	else if (ft == 3)
	{
		(*flag) = 1;
		write(1, " ", 1);
	}
	return ;
}

void	ft_printf_flag_app_2(int ft, int *flag, long n)
{
	if (ft == 1)
	{
		if (n < 0)
			(*flag) += 1;
	}
	if (ft == 2)
	{
		if ((*flag) < 1)
			(*flag) = 0;
	}
	return ;
}
