/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:15:40 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/03 18:35:54 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creat_imgs(t_connect_data *map)
{
	int	dim;

	dim = 0;
	map->imgs.floor = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/floor.xpm", &dim, &dim);
	map->imgs.wall = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/wall.xpm", &dim, &dim);
	map->imgs.player = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/player.xpm", &dim, &dim);
	map->imgs.coin = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/coin.xpm", &dim, &dim);
	map->imgs.exit = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/close_door.xpm", &dim, &dim);
	map->imgs.exit_o = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/open_door.xpm", &dim, &dim);
	map->imgs.player_back = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/player_back.xpm", &dim, &dim);
	map->imgs.player_rt = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/player_right.xpm", &dim, &dim);
	map->imgs.plr_lt = mlx_xpm_file_to_image(map->mlx_ptr \
		, "./textures/player_left.xpm", &dim, &dim);
}

void	tab_2_f(t_connect_data *map)
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
				, map->win_ptr, map->imgs.floor, dim_x, dim_y);
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
	if (!map->imgs.floor)
		exit(write(1, "Error : Img not Found !\n", 22));
	tab_2_f(map);
}

void	tab_2(t_connect_data *map)
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
					, map->win_ptr, map->imgs.wall, dim_x, dim_y);
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
	if (!map->imgs.wall)
		exit(write(1, "Error : Img not Found !\n", 22));
	tab_2(map);
}
