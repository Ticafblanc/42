/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:31:37 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:31:41 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_map(t_vars *vars)
{
	free (vars->img->wall);
	free (vars->img->emp);
	free (vars->img->item);
	free (vars->img->exit);
	free (vars->img->enemy);
	free (vars->img->player_down);
	free (vars->img->player_up);
	free (vars->img->player_left);
	free (vars->img->player_right);
	free (vars->img);
	ft_free_pp(vars->map);
	free(vars);
}

void	update_utils(t_vars *vars)
{
	if (vars->player_side == DOWN && vars->time == 0)
	{
		vars->player_side = LEFT;
		vars->time = 5000;
	}
	else if (vars->player_side == LEFT && vars->time == 0)
	{
			vars->player_side = UP;
			vars->time = 5000;
	}
	else if (vars->player_side == UP && vars->time == 0)
	{
			vars->player_side = RIGHT;
			vars->time = 5000;
	}
	else if (vars->player_side == RIGHT && vars->time == 0)
	{
			vars->player_side = DOWN;
			vars->time = 5000;
	}
}
