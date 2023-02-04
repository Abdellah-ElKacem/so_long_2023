/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:44:28 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/03 16:37:40 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tab_2_2(t_connect_data *map)
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
					, map->win_ptr, map->imgs.coin, dim_x, dim_y);
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
	if (!map->imgs.coin)
		exit(write(1, "Error : Img not Found !\n", 22));
	tab_2_2(map);
}

void	tab_2_3(t_connect_data *map)
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
					, map->win_ptr, map->imgs.exit, dim_x, dim_y);
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
	if (!map->imgs.exit || !map->imgs.exit_o)
		exit(write(1, "Error : Img not Found !\n", 22));
	tab_2_3(map);
}
