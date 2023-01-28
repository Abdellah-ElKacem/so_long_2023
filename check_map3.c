/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:44:28 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/28 18:40:51 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tab_2_2(t_connect_data *map, t_images img)
{
	int			x;
	int			y;
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
			if (map->map[x][y] == 'C')
				mlx_put_image_to_window(map->mlx_ptr \
					, map->win_ptr, img.coin, dim_x, dim_y);
			dim_x += 32;
			y++;
		}
		dim_y += 32;
		dim_x = 0;
		x++;
		y = 0;
	}
}

void	put_map2(t_connect_data *map)
{
	t_images	img;
	int			dim;

	dim = 0;
	img.coin = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/coin.xpm", &dim, &dim);
	tab_2_2(map, img);
}

void	tab_2_3(t_connect_data *map, t_images img)
{
	int			x;
	int			y;
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
			if (map->map[x][y] == 'E')
				mlx_put_image_to_window(map->mlx_ptr \
					, map->win_ptr, img.exit, dim_x, dim_y);
			dim_x += 32;
			y++;
		}
		dim_y += 32;
		dim_x = 0;
		x++;
		y = 0;
	}
}

void	put_map3(t_connect_data *map)
{
	t_images	img;
	int			dim;

	dim = 0;
	img.exit = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/exit.xpm", &dim, &dim);
	tab_2_3(map, img);
}
