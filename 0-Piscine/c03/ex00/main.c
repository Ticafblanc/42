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
int ft_strcmp(char *s1, char *s2);

int main()
{
	char	s1[] = "sAlut";
	char	s2[] = "salut";
	char	s12[] = "salut";
	char	s22[] = "salut";
	char	s13[] = "salut";
	char	s23[] = "sAlut";
	unsigned int	a;

	a = 8;
	printf("%d\n", a);
	a = ft_strcmp(s1, s2);
	printf("%d = -\n", a);
	a = ft_strcmp(s12, s22);
	printf("%d = 0\n", a);
	a = ft_strcmp(s13, s23);
	printf("%d = +\n", a);
	return(0);
}
