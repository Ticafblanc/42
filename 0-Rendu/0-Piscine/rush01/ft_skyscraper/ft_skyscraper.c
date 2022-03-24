/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:40:15 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/02 14:41:19 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int fill_arr(int arr[4][4], int argv[16], int pos)
{
	int val;

	if (pos == 16)
		return (1);
	val = 0;
	while (++val <= 4)
	{
		if (check_double(arr, pos, val) == 0)
		{
			arr[pos / 4][pos % 4] = val;
			if (check_case(arr, pos, argv) == 0)
			{
				if (fill_arr(arr, argv, pos + 1) == 1)
					return (1);
			}
			else
				arr[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

void put_solution(int arr[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(arr[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int *save_argv(char *str)
{
    int i;
    int j;
    int *argv;

    if (!(argv = malloc(sizeof(int) * 16)))
        return (0);
    i = -1;
    j = 0;
    while (str[++i] != '\0')
        if (str[i] >= '0' && str[i] <= '9')
            argv[j++] = ft_atoi(str + i);
    return (argv);
}


int check_argc(int ac, char **av)
{
    if (ac != 2)
        return (1);
    if (ft_strlen(av[1]) != 31)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
	int arr[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *argv;

	if (check_argc(ac, av) == 1)
		return (0);
	argv = save_argv(av[1]);
	if (fill_arr(arr, argv, 0) == 1)
		put_solution(arr);
	else
		ft_putstr("error\n");
	return (0);
}
