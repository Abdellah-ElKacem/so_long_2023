/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:08:07 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/01 12:47:07 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_err(t_images img)
{
	if (!img.player)
		exit(write(1, "Error : Img not Found !\n", 22));
}

void	put_map1(t_connect_data *map)
{
	t_images	img;
	int			dim;

	img.player = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/player.xpm", &dim, &dim);
	img_err(img);
	while (map->x < map->map_height)
	{
		while (map->y < map->map_weight)
		{
			if (map->map[map->x][map->y] == 'P')
			{
				mlx_put_image_to_window(map->mlx_ptr \
					, map->win_ptr, img.player, map->dim_x, map->dim_y);
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
