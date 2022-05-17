/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:31:18 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:31:23 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_side(t_vars *vars, int keycode)
{
	if (keycode == DOWN)
		vars->player_side = DOWN;
	else if (keycode == UP)
		vars->player_side = UP;
	else if (keycode == RIGHT)
		vars->player_side = RIGHT;
	else if (keycode == LEFT)
		vars->player_side = LEFT;
}

void	check_move(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'C')
		vars->item--;
	if (vars->map[y][x] == 'E')
		vars->end_game = 1;
	if (vars->map[y][x] == 'V')
	{
		vars->enemy_win = 1;
		vars->end_game = 1;
	}
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->map[y][x] = 'P';
	vars->player_y = y;
	vars->player_x = x;
	vars->steps++;
}
