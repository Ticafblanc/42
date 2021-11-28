#include <stdio.h>
char	*ft_strupcase(char *str);
int main()
{
	char	str[] = "abc123";
;
	printf("%s", str);
	ft_strupcase(str);
	printf("%s", str);
	return(0);
}
