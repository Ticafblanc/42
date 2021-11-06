#include <stdio.h>
int	ft_str_is_alpha(char *str);
int main()
{
	char	str1[] = "AZaz";
	char	str2[] = "AZ?az";
	int	a;

	a = 2;
	a = ft_str_is_alpha(str1);
	printf("%d\n", a);
	a = ft_str_is_alpha(str2);
	printf("%d\n", a);
	return(0);
}

