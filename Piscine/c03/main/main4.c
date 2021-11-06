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
char	*ft_strstr(char *str, char *to_find);

int main()
{
	char	*str = "salut comment ca va ?";
	char	to_find[] = "comment";

	printf("%s\n", str);
	str = ft_strstr(str, to_find);
	printf("%s\n", str);
	return(0);
}
