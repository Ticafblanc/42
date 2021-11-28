#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	i;
	int a;
	int	min;
	int	max;
	int *ptr;

	min = 5;
	max = 16;
	i = 0;
	a = ft_ultimate_range(&ptr, min, max);
	while (ptr[i])
	{
		printf("%d\n", ptr[i]);
		i++;
	}
	free(ptr);
	printf("%d\n", a);
}
