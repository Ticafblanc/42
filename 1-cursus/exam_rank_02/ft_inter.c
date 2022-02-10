/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:52:49 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/10 14:53:43 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void inter(char *s1, char *s2)
{
	int	i;
	int	i2;
	int i3;
	char str[128];

	i = 0;
	i2 = 0;
	i3 = 0;
	while (i < 127)
		str[i++] = '\0';
	i = 0;
	while (s1[i])
	{
	   while (s2[i2])
	   {
		   i3 = s1[i];
		   if (s1[i] == s2[i] && str[i3] != s1[i])
		   {
			   str[i3] = s1[i];
			   write (1, &s1[i], 1);
		   }
		   i2++;
	   }
	   i2 = 0;
	   i++;
	}
}

 int     main(int argc, char **argv)
{
	if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n", 1);
 	return (0);
}
