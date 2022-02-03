/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_fill_arr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@students.42quebec.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:46:35 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/02 14:48:33 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int check_col_up(int arr[4][4], int pos, int argv[16])
{
	int i;
	int high_tower;
	int visible_towers;

	i = 0;
	high_tower = 0;
	visible_towers = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (arr[i][pos % 4] > high_tower)
			{
				high_tower = arr[i][pos % 4];
				visible_towers++;
			}
			i++;
		}
		if (argv[pos % 4] != visible_towers)
			return (1);
	}
	return (0);
}



int check_col_down(int arr[4][4], int pos, int argv[16])
{
	int i;
	int high_tower;
	int visible_towers;

	i = 3;
	high_tower = 0;
	visible_towers = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (arr[i][pos % 4] > high_tower)
			{
				high_tower = arr[i][pos % 4];
				visible_towers++;
			}
			i--;
		}
		if (argv[4 + pos % 4] != visible_towers)
			return (1);
	}
	return (0);
}

int check_row_right(int arr[4][4], int pos, int argv[16])
{
    int i;
    int high_tower;
    int visible_towers;

    i = 4;
    high_tower = 0;
    visible_towers = 0;
    if (pos % 4 == 3)
    {
        while (--i >= 0)
        {
            if (arr[pos / 4][i] > high_tower)
            {
                high_tower = arr[pos / 4][i];
                visible_towers++;
            }
        }
        if (argv[12 + pos / 4] != visible_towers)
            return (1);
    }
    return (0);
}

int check_row_left(int arr[4][4], int pos, int argv[16])
{
	int i;
	int high_tower;
	int visible_towers;

	i = 0;
	high_tower = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (arr[pos / 4][i] > high_tower)
			{
				high_tower = arr[pos / 4][i];
				visible_towers++;
			}
			i++;
		}
		if (argv[8 + pos / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int check_case(int arr[4][4], int pos, int argv[16])
{
	if (check_row_left(arr, pos, argv) == 1)
		return (1);
	if (check_row_right(arr, pos, argv) == 1)
		return (1);
	if (check_col_down(arr, pos, argv) == 1)
		return (1);
	if (check_col_up(arr, pos, argv) == 1)
		return (1);
	return (0);
}

int check_double(int arr[4][4], int pos, int val)
{
    int i;

    i = -1;
    while (++i < pos / 4)
        if (arr[i][pos % 4] == val)
            return (1);
    i = -1;
    while (++i < pos % 4)
        if (arr[pos / 4][i] == val)
            return (1);
    return (0);
}
