/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_strerror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 06:03:49 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/06/09 05:44:02 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_exit_strerror(int errnum)
{
	printf("%s", strerror(errnum));
	exit(EXIT_FAILURE);
}
