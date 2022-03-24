#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	*tab;
	int	min;
	int	max;
	int	count;

	count = 0;
	min = 1;
	max = 100;
	tab = ft_range(min, max);
	while (tab[count])
	{
		printf("%d\n", tab[count]);
		count++;
	}
	free(tab);
}