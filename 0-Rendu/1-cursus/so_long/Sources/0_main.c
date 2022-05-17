/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:29:46 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:30:06 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	close_game(t_vars *vars)
{
	free_map(vars);
	exit(EXIT_SUCCESS);
}

int	read_key(int keycode, t_vars *vars)
{
	int	y;
	int	x;

	if (keycode == ESC)
		close_game(vars);
	if (vars->end_game == 1 || (keycode != UP && keycode != DOWN
			&& keycode != LEFT && keycode != RIGHT))
		return (0);
	y = vars->player_y;
	x = vars->player_x;
	if (keycode == UP)
		y--;
	else if (keycode == DOWN)
		y++;
	else if (keycode == LEFT)
		x--;
	else if (keycode == RIGHT)
		x++;
	check_side(vars, keycode);
	if (vars->map[y][x] != '1')
		check_move (vars, y, x);
	put_game(vars);
	vars->time = 50000;
	return (0);
}

int	update(t_vars *vars)
{
	if (vars->time > 0)
	{
		vars->time--;
		return (0);
	}
	update_utils(vars);
	put_game(vars);
	return (0);
}

t_vars	*init_t_vars(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		ft_exit_perror("init t_struct t_vars failure", EXIT_FAILURE);
	vars->error_map = 0;
	vars->wall_x = 0;
	vars->wall_y = 0;
	vars->enemy_win = 0;
	vars->end_game = 0;
	vars->steps = 0;
	vars->player_side = DOWN;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->item = 0;
	vars->time = 50000;
	return (vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc == 2 && ft_check_extension(argv[1], ".ber") > 0)
	{
		vars = init_t_vars();
		check_map(argv[1], vars);
		init_game(vars);
		mlx_hook(vars->win, ON_DESTROY, 0, close_game, (void *)vars);
		mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, read_key, (void *)vars);
		mlx_loop_hook(vars->mlx, update, vars);
		mlx_loop(vars->mlx);
	}
	ft_exit_perror("just one map extension .ber !! ", EXIT_FAILURE);
}
