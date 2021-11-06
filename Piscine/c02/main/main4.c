#include <stdio.h>
int	ft_str_is_lowercase(char *str);
int main()
{
	char	str1[] = "ahchcdvc";
	char	str2[] = "wjdncm&jkdjdj";
	int	a;

	a = 2;
	a = ft_str_is_lowercase(str1);
	printf("%d\n", a);
	a = ft_str_is_lowercase(str2);
	printf("%d\n", a);
	return(0);
}
