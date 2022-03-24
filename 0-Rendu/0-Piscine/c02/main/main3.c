#include <stdio.h>
int	ft_str_is_numeric(char *str);
int main()
{
	char	str1[] = "12424";
	char	str2[] = "1512&55";
	int	a;

	a = 2;
	a = ft_str_is_numeric(str1);
	printf("%d\n", a);
	a = ft_str_is_numeric(str2);
	printf("%d\n", a);
	return(0);
}

