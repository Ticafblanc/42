/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-1_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:30:37 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:30:41 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_caractere(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (++y != vars->wall_y)
	{
		x = 0;
		while (++x != vars->wall_x)
			if (check_cara(vars, x, y) < 0)
				return (-1);
	}
	if (vars->end_game > 0 && vars->item > 0
		&& vars->steps == 1)
	{
		vars->end_game = 0;
		vars->steps = 0;
		return (0);
	}
	return (-1);
}

int	check_wall_up(t_vars *vars)
{
	while (vars->map[vars->wall_y][vars->wall_x])
	{	
		if (vars->map[vars->wall_y][vars->wall_x] == '1')
			vars->wall_x++;
		else
			return (-1);
	}
	vars->wall_x--;
	return (0);
}

int	check_wall_side(t_vars *vars)
{
	while (vars->map[vars->wall_y])
	{
		if (ft_strlen(vars->map[vars->wall_y]) != (size_t)vars->wall_x + 1
			|| vars->map[vars->wall_y][0] != '1'
			|| vars->map[vars->wall_y][vars->wall_x] != '1')
			return (-1);
		vars->wall_y++;
	}
	vars->wall_y--;
	return (1);
}

int	check_wall_down(t_vars *vars)
{
	int	i;

	i = 1;
	while (vars->map[vars->wall_y][i])
	{
		if (vars->map[vars->wall_y][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_cara(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'E')
	{
		vars->end_game++;
		return (0);
	}
	else if (vars->map[y][x] == 'C')
	{
		vars->item++;
		return (0);
	}
	else if (vars->map[y][x] == 'V')
		return (0);
	else if (vars->map[y][x] == '0')
		return (0);
	else if (vars->map[y][x] == '1')
		return (0);
	else if (vars->map[y][x] == 'P')
	{
		vars->steps++;
		vars->player_x = x;
		vars->player_y = y;
		return (0);
	}
	return (-1);
}
