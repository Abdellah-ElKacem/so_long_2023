/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:48:31 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/22 16:44:01 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

    // player->player_front = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player.xpm", &dimension, &dimension);
	// player->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &dimension, &dimension);
	// player->player_right = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_right.xpm", &dimension, &dimension);
	// player->player_left = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_left.xpm", &dimension, &dimension);

void	find_player(t_connect_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'P')
			{
				data->player_x = y;
				data->player_y = x;
				return;
			}
			y++;
		}
		x++;
	}
}

// void move_up(t_connect_data *data)
// {
//     t_images *imgs;
//     int dimension;
    
//     dimension = 0;
// 	printf(",,,");
//     if (data->map[data->player_x - 1][data->player_y] != '1')
// 	{
// 		if (data->map[data->player_x - 1][data->player_y] != 'E')
// 		{
// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, imgs->floor, data->player_x * 32, data->player_y * 32);
// 			data->player_x -= 1;
// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, imgs->player_back, data->player_x * 32, data->player_y * 32);
// 		}
// 	}
// }



int ft_moves(int key)
{
    t_images *imgs;
    t_connect_data *data;

    if (key == 53)
		exit(write(1, "LOSER! :/ ", 10));
    if (key == 13 || key == 126)
        // move_up(data);
	{
		printf("<<<false\n");
    	if (data->map[data->player_x - 1][data->player_y] != '1')
		{
		printf("<<<true\n");
			if (data->map[data->player_x - 1][data->player_y] != 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, imgs->floor, data->player_x * 32, data->player_y * 32);
				data->player_x -= 1;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, imgs->player_back, data->player_x * 32, data->player_y * 32);
			}
		}
	}
    return (0);
}
