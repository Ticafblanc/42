/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:31:05 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:31:09 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*read_map(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'E')
		return (vars->img->exit->img);
	else if (vars->map[y][x] == 'C')
		return (vars->img->item->img);
	else if (vars->map[y][x] == 'V')
		return (vars->img->enemy->img);
	else if (vars->map[y][x] == '1')
		return (vars->img->wall->img);
	else if (vars->map[y][x] == '0')
		return (vars->img->emp->img);
	else
	{
		if (vars->player_side == DOWN)
			return (vars->img->player_down->img);
		else if (vars->player_side == UP)
			return (vars->img->player_up->img);
		else if (vars->player_side == RIGHT)
			return (vars->img->player_right->img);
		else
			return (vars->img->player_left->img);
	}
}

void	put_game(t_vars *vars)
{
	int		y;
	int		x;
	char	*str;

	y = -1;
	while (++y <= vars->wall_y)
	{
		x = -1;
		while (++x <= vars->wall_x)
			mlx_put_image_to_window(vars->mlx, vars->win,
				read_map(vars, y, x), x * TILES, y * TILES);
	}
	mlx_string_put(vars->mlx, vars->win, 25, 25, 0xFFFF00, "Move :");
	str = ft_itoa(vars->steps);
	mlx_string_put(vars->mlx, vars->win, 75, 25, 0xFFFF00, str);
	free(str);
	if (vars->end_game == 1 && vars->item == 0)
		mlx_string_put(vars->mlx, vars->win, 100, 25,
			0xFFFF00, "WIN esc to quit");
	if (vars->enemy_win == 1 || (vars->end_game == 1 && vars->item > 0))
		mlx_string_put(vars->mlx, vars->win, 100, 25,
			0xFFFF00, "LOSE esc to quit");
}
