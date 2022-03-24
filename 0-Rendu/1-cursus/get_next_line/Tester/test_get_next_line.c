#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdio.h>

void test_petites_lignes()
{
    int fd;
	char *str;

    fd = open("test_petites_lignes.txt", O_RDONLY);

    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    close(fd);
}

void test_grandes_lignes()
{
    int fd;
	char *str;

    fd = open("test_grandes_lignes.txt", O_RDONLY);

    str = get_next_line(fd);
	printf("%s", str);
	free(str);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
    close(fd);
}

void test_meme_lignes()
{
    int fd;
	char *str;

    fd = open("test_meme_lignes.txt", O_RDONLY);

    str = get_next_line(fd);
	printf("%s", str);
	free(str);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
    close(fd);
}

void test_lignes_vide()
{
    int fd;
	char *str;

    fd = open("test_lignes_vide.txt", O_RDONLY);

    str = get_next_line(fd);
	printf("%s", str);
	free(str);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
    str = get_next_line(fd);
    printf("%s", str);
	free(str);
    close(fd);
}

int main(void)
{
    test_petites_lignes();
    test_grandes_lignes();
    test_lignes_vide();
    test_meme_lignes();
    return (0);
}
