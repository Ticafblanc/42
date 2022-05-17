/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:30:47 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:30:53 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_t_img(t_vars *vars)
{
	vars->img = (t_img *)malloc(sizeof(t_img));
	vars->img->wall = (t_asset *)malloc(sizeof(t_asset));
	vars->img->emp = (t_asset *)malloc(sizeof(t_asset));
	vars->img->item = (t_asset *)malloc(sizeof(t_asset));
	vars->img->exit = (t_asset *)malloc(sizeof(t_asset));
	vars->img->enemy = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_down = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_up = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_left = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_right = (t_asset *)malloc(sizeof(t_asset));
	if (!vars->img || !vars->img->wall || !vars->img->emp || !vars->img->item
		|| !vars->img->exit || !vars->img->enemy || !vars->img->player_down
		|| !vars->img->player_up || !vars->img->player_left
		|| !vars->img->player_right)
	{
		ft_free_pp(vars->map);
		free(vars);
		ft_exit_perror("init t_struct t_img failure", EXIT_FAILURE);
	}	
}

void	init_asset(t_vars *vars)
{
	vars->img->wall->img = mlx_xpm_file_to_image(vars->mlx, PATH_W,
			&vars->img->wall->width, &vars->img->wall->height);
	vars->img->emp->img = mlx_xpm_file_to_image(vars->mlx, PATH_E,
			&vars->img->emp->width, &vars->img->emp->height);
	vars->img->item->img = mlx_xpm_file_to_image(vars->mlx, PATH_I,
			&vars->img->item->width, &vars->img->item->height);
	vars->img->exit->img = mlx_xpm_file_to_image(vars->mlx, PATH_EX,
			&vars->img->exit->width, &vars->img->exit->height);
	vars->img->enemy->img = mlx_xpm_file_to_image(vars->mlx, PATH_V,
			&vars->img->enemy->width, &vars->img->enemy->height);
	vars->img->player_down->img = mlx_xpm_file_to_image(vars->mlx, PATH_PD,
			&vars->img->player_down->width, &vars->img->player_down->height);
	vars->img->player_up->img = mlx_xpm_file_to_image(vars->mlx, PATH_PT,
			&vars->img->player_up->width, &vars->img->player_up->height);
	vars->img->player_left->img = mlx_xpm_file_to_image(vars->mlx, PATH_PL,
			&vars->img->player_left->width, &vars->img->player_left->height);
	vars->img->player_right->img = mlx_xpm_file_to_image(vars->mlx, PATH_PR,
			&vars->img->player_right->width, &vars->img->player_right->height);
}

void	init_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->wall_x + 1) * TILES,
			(vars->wall_y + 1) * TILES, "so_long");
	init_t_img(vars);
	init_asset(vars);
	put_game(vars);
}
