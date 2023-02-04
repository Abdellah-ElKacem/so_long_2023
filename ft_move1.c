/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:23:59 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/03 13:49:02 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_connect_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] != '1'
		&& data->map[data->player_y + 1][data->player_x] != 'E')
	{
		if (data->map[data->player_y + 1][data->player_x] == 'C')
			see_down_coin(data);
		else
			see_down_else(data);
		player_move(data);
	}
	else if (data->coin == 0
		&& data->map[data->player_y + 1][data->player_x] == 'E')
		exit(write(1, "\n!----- Congraluation -----!\n	You Win GG\n", 42));
}

void	see_right_coin(t_connect_data *data)
{
	data->coin -= 1;
	data->map[data->player_y][data->player_x + 1] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_x += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.player_rt, data->player_x * 32, data->player_y * 32);
}

void	see_right_else(t_connect_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_x += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.player_rt, data->player_x * 32, data->player_y * 32);
}

void	move_right(t_connect_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] != '1'
		&& data->map[data->player_y][data->player_x + 1] != 'E')
	{
		if (data->map[data->player_y][data->player_x + 1] == 'C')
			see_right_coin(data);
		else
			see_right_else(data);
		player_move(data);
	}
	else if (data->coin == 0
		&& data->map[data->player_y][data->player_x + 1] == 'E')
		exit(write(1, "\n!----- Congraluation -----!\n	You Win GG\n", 42));
}

void	see_left_coin(t_connect_data *data)
{
	data->coin -= 1;
	data->map[data->player_y][data->player_x - 1] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_x -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.plr_lt, data->player_x * 32, data->player_y * 32);
}
