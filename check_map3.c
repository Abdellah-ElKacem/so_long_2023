/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:08:07 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/02 14:16:08 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map1(t_connect_data *map)
{
	if (!map->imgs.player || !map->imgs.player_back
		|| !map->imgs.player_rt || !map->imgs.plr_lt)
		exit(write(1, "Error : Img not Found !\n", 22));
	while (map->x < map->map_height)
	{
		while (map->y < map->map_weight)
		{
			if (map->map[map->x][map->y] == 'P')
			{
				mlx_put_image_to_window(map->mlx_ptr \
					, map->win_ptr, map->imgs.player, map->dim_x, map->dim_y);
				map->player_x = map->y;
				map->player_y = map->x;
			}
			map->dim_x += 32;
			map->y++;
		}
		map->dim_y += 32;
		map->dim_x = 0;
		map->x++;
		map->y = 0;
	}
}
