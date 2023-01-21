/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:48:31 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/21 16:30:06 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_moves(int key)
{
    t_images *imgs;
    t_connect_data *data;
    int dimension;
    
    dimension = 0;
    imgs->player_front = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player.xpm", &dimension, &dimension);
	imgs->player_back = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_back.xpm", &dimension, &dimension);
	imgs->player_right = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_right.xpm", &dimension, &dimension);
	imgs->player_left = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_left.xpm", &dimension, &dimension);
    
    printf("%d\n", key);
    if (key == 53)
	{
		write(1, "LOSER! :/ ", 10);
		exit (0);
	}
    return (0);
}
