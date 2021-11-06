#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int main(void)
{
	char	*srco;
	char	*srcr;

	srco = "je suis le loup";
	srcr = ft_strdup(srco);
	printf("%s\n", srcr);
	free(srcr);
}