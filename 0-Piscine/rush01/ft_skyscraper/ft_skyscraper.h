#ifndef FT_SKYSCRAPER_H
# define FT_SKYSCRAPER_H
#include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

//ft_skyscraper_utils.c
void ft_putchar(char c);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_atoi(char *str);
void ft_putnbr(int nb);

//ft_scyscraper_fill_arr.c
int check_col_up(int arr[4][4], int pos, int argv[16]);
int check_col_down(int arr[4][4], int pos, int argv[16]);
int check_row_right(int arr[4][4], int pos, int argv[16]);
int check_row_left(int arr[4][4], int pos, int argv[16]);
int check_case(int arr[4][4], int pos, int argv[16]);
int check_double(int arr[4][4], int pos, int val);

//ft_skyscraper.c
int fill_arr(int arr[4][4], int argv[16], int pos);
void put_solution(int arr[4][4]);
int *save_argv(char *str);
int check_argc(int ac, char **av);

#endif
