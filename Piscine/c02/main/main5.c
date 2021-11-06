#include <stdio.h>
int	ft_str_is_uppercase(char *str);
int main()
{
	char	str1[] = "SDFGHB";
	char	str2[] = "SDFGHJ&XCVB";
	int	a;

	a = 2;
	a = ft_str_is_uppercase(str1);
	printf("%d\n", a);
	a = ft_str_is_uppercase(str2);
	printf("%d\n", a);
	return(0);
}
