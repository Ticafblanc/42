#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int	n);

int main()
{
	char	dest[] = "0";
	char	src[] = "coucou";
	int	n = 10;

	printf("dest %sfin\n", dest);
	ft_strncpy(dest, src, n);
	printf("dest %sfin\n", dest);
	return(0);
}
