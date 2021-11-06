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
int ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	char	s1[] = "sAlut";
	char	s2[] = "salut";
	char	s12[] = "salut";
	char	s22[] = "salut";
	char	s13[] = "salut";
	char	s23[] = "sAlut";
	unsigned int	a;
	unsigned int	b;

	a = 8;
	b = 3;
	printf("%d\n", a);
	a = ft_strncmp(s1, s2, b);
	printf("%d = -\n", a);
	a = ft_strncmp(s12, s22, b);
	printf("%d = 0\n", a);
	a = ft_strncmp(s13, s23, b);
	printf("%d = +\n", a);
	return(0);
}
