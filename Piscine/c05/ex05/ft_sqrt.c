#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;

	if (nb <= 0)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	i = 0;
	while (i <= nb / 2 && i <= 46341)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
int		i;
 
 	i = 0;
 	if (nb <= 0)
 		return (0);
 	while (i * i < nb && i <= 46340)
 		i++;
 	if (i * i == nb)
 		return (i);
 	else
 		return (0);