#include <stdio.h>
int	ft_str_is_printable(char *str);
int main()
{
	char	str1[] = "SDFGHB15651";
	char	str2[] = "ç";
	int	a;

	a = 2;
	a = ft_str_is_printable(str1);
	printf("%d\n", a);
	a = ft_str_is_printable(str2);
	printf("%d\n", a);
	return(0);
}
