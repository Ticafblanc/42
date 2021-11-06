#include <stdio.h>
char    *ft_strcpy(char *dest, char *src);

int main()
{
    char    dest[] = "0";
    char    src[] = "coucou";

    printf("dest %s\n", dest);
    ft_strcpy(dest, src);
    printf("dest %s\n", dest);
    return(0);
}