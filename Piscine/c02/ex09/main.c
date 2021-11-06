#include <stdio.h>
char	*ft_strcapitalize(char *str);
int main()
{
	char	str[] = "sAlut, comMent tu vAs ? 42Mots quarante-deux; cinquante+et+un";
;
	printf("%s\n", str);
	ft_strcapitalize(str);
	printf("%s\n", str);
	return(0);
}
