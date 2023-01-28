/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:15:40 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/28 19:20:01 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tab_2_f(t_connect_data *map, t_images img)
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
			mlx_put_image_to_window(map->mlx_ptr \
				, map->win_ptr, img.floor, dim_x, dim_y);
			dim_x += 32;
			y++;
		}
		dim_y += 32;
		dim_x = 0;
		x++;
		y = 0;
	}
}

void	put_map_f(t_connect_data *map)
{
	t_images	img;
	int			dim;

	dim = 0;
	img.floor = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/floor.xpm", &dim, &dim);
	tab_2_f(map, img);
}

void	tab_2(t_connect_data *map, t_images img)
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
			if (map->map[x][y] == '1')
				mlx_put_image_to_window(map->mlx_ptr \
					, map->win_ptr, img.wall, dim_x, dim_y);
			dim_x += 32;
			y++;
		}
		dim_y += 32;
		dim_x = 0;
		x++;
		y = 0;
	}
}

void	put_map(t_connect_data *map)
{
	t_images	img;
	int			dim;

	dim = 0;
	img.wall = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/wall.xpm", &dim, &dim);
	tab_2(map, img);
}

void	put_map1(t_connect_data *map)
{
	t_images	img;
	int			dim;

	dim = 0;
	img.player = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/player.xpm", &dim, &dim);
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
