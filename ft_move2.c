/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:42:07 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/03 19:53:06 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	see_left_else(t_connect_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.floor, data->player_x * 32, data->player_y * 32);
	data->player_x -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
		, data->imgs.plr_lt, data->player_x * 32, data->player_y * 32);
}

void	move_left(t_connect_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] != '1'
		&& data->map[data->player_y][data->player_x - 1] != 'E')
	{
		if (data->map[data->player_y][data->player_x - 1] == 'C')
			see_left_coin(data);
		else
			see_left_else(data);
		player_move(data);
	}
	else if (data->coin == 0
		&& data->map[data->player_y][data->player_x - 1] == 'E')
		exit(write(1, "\n!----- Congraluation -----!\n	You Win GG\n", 42));
}

void	open_exit(t_connect_data *map, int x, int y)
{
	int			dim_x;
	int			dim_y;

	dim_x = 0;
	dim_y = 0;
	x = 0;
	y = 0;
	while (x < map->map_height)
	{
		while (y < map->map_weight)
		{
			if (map->map[x][y] == 'E' && map->coin > 0)
				mlx_put_image_to_window(map->mlx_ptr \
					, map->win_ptr, map->imgs.exit, dim_x, dim_y);
			if (map->map[x][y] == 'E' && map->coin == 0)
				mlx_put_image_to_window(map->mlx_ptr \
					, map->win_ptr, map->imgs.exit_o, dim_x, dim_y);
			dim_x += 32;
			y++;
		}
		dim_y += 32;
		dim_x = 0;
		x++;
		y = 0;
	}
}

int	ft_moves(int key, t_connect_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 53)
		exit(write(1, "LOSER! :/ ", 10));
	if (key == 13 || key == 126)
		move_up(data);
	if (key == 1 || key == 125)
		move_down(data);
	if (key == 0 || key == 123)
		move_left(data);
	if (key == 2 || key == 124)
		move_right(data);
	open_exit(data, x, y);
	return (0);
}
