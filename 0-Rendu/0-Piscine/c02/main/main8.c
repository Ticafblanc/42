#include <stdio.h>
char	*ft_strlowcase(char *str);
int main()
{
	char	str[] = "ABC123XYZ";
;
	printf("%s", str);
	ft_strlowcase(str);
	printf("%s", str);
	return(0);
}
