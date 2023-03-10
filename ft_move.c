/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:48:31 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/03 13:47:05 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	see_up_coin(t_connect_data *data)
{
	data->coin -= 1;
	data->map[data->player_y - 1][data->player_x] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_y -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.player_back, data->player_x * 32, data->player_y * 32);
}

void	see_up_else(t_connect_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_y -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.player_back, data->player_x * 32, data->player_y * 32);
}

void	move_up(t_connect_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] != '1'
		&& data->map[data->player_y - 1][data->player_x] != 'E')
	{
		if (data->map[data->player_y - 1][data->player_x] == 'C')
			see_up_coin(data);
		else
			see_up_else(data);
		player_move(data);
	}
	else if (data->coin == 0
		&& data->map[data->player_y - 1][data->player_x] == 'E')
		exit(write(1, "\n!----- Congraluation -----!\n	You Win GG\n", 42));
}

void	see_down_coin(t_connect_data *data)
{
	data->coin -= 1;
	data->map[data->player_y + 1][data->player_x] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_y += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.player, data->player_x * 32, data->player_y * 32);
}

void	see_down_else(t_connect_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_y += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.player, data->player_x * 32, data->player_y * 32);
}
