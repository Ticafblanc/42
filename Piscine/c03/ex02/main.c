/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:58:35 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/12 15:20:46 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
 char *ft_strcat(char *dest, char *src);

int main()
{
	char	dest[] = "salut";
	char	src[] = "comment va tu";

	printf("%s\n", dest);
	ft_strcat(dest, src);
	printf("%s\n", dest);
	return(0);
}
