/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:41:14 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/22 16:23:39 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_connect_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_height)
	{
		if (data->map[x][0] == '1' && data->map[x][data->map_weight - 1] == '1')
			x++;
		else
			return (1);
	}
	while (y < data->map_weight)
	{
		if (data->map[0][y] == '1' && data->map[data->map_height - 1][y] == '1')
			y++;
		else
			return (1);
	}
	return (0);
}

int	check_map_rec(t_connect_data *data)
{
	int	x;

	x = 0;
	while (x < data->map_height - 1)
	{
		if (ft_strlen(data->map[x]) == data->map_weight + 1)
			x++;
		else
			return (1);
	}
	if (ft_strlen(data->map[x]) != data->map_weight)
		return 1;
	return (0);
}

int	check_player(t_connect_data *data)
{
	int	x;
	int	y;
	int	player;

	x = 0;
	player = 0;
	while (x < data->map_height)
	{
		y = 0;
		while (y < data->map_weight)
		{
			if (data->map[x][y] == 'P')
				player++;
			y++;
		}
		y = 0;
		x++;
	}
	if (player == 1)
		return (1);
	return (0);
}

int	check_collection(t_connect_data *data)
{
	int	x;
	int	y;
	int	collection;

	x = 0;
	collection = 0;
	while (x < data->map_height)
	{
		while (y < data->map_weight)
		{
			if (data->map[x][y] == 'C')
				collection++;
			y++;
		}
		y = 0;
		x++;
	}
	if (collection >= 1)
		return (1);
	return (0);
}

int	check_exit(t_connect_data *data)
{
	int	x;
	int	y;
	int	exit;

	x = 0;
	exit = 0;
	while (x < data->map_height)
	{
		while (y < data->map_weight)
		{
			if (data->map[x][y] == 'E')
				exit++;
			y++;
		}
		y = 0;
		x++;
	}
	if (exit == 1)
		return (1);
	return (0);
}

int	check_caracter(t_connect_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_height)
	{
		while (y < data->map_weight)
		{
			if (data->map[x][y] == 'E' || data->map[x][y] == '1'|| data->map[x][y] == '0'
				|| data->map[x][y] == 'P' || data->map[x][y] == 'C')
					y++;
			else
				return (1);
		}
		y = 0;
		x++;
	}
	return (0);
}

void	ft_checker(t_connect_data *check)
{
	if (check_wall(check) == 1)
		exit(write(1, "Error Map Check Walls !", 24));
	if (check_player(check) != 1)
		exit(write(1, "Error check player !", 21));
	if (check_collection(check) != 1)
		exit(write(1, "Error Need Collections !", 25));
	if (check_exit(check) != 1)
		exit(write(1, "Error found check the exit !", 28));
	if (check_caracter(check) == 1)
		exit(write(1, "Error Invalid Map !", 20));
	if (check_map_rec(check) == 1)
		exit(write(1, "Error too many carac !", 23));
}

void put_map(t_connect_data map)
{
	t_images img;
	int x;
	int y;
	int dim;
	int dim_x;
	int dim_y;

	dim = 0;
	dim_x = 0;
	dim_y = 0;
	img.floor = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/floor.xpm", &dim, &dim);
	img.player = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/player.xpm", &dim, &dim);
	img.player_back = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/player_back.xpm", &dim, &dim);
	img.player_right = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/player_right.xpm", &dim, &dim);
	img.player_left = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/player_left.xpm", &dim, &dim);
	img.coin = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/coin.xpm", &dim, &dim);
	img.exit = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/exit.xpm", &dim, &dim);
	img.wall = mlx_xpm_file_to_image(map.mlx_ptr, "./textures/wall.xpm", &dim, &dim);
	x = 0;
	y = 0;
	while (x < map.map_height)
	{
		while (y < map.map_weight)
		{
			mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, img.floor, dim_x, dim_y);
			if (map.map[x][y] == '1')
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, img.wall, dim_x, dim_y);
			else if (map.map[x][y] == 'P')
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, img.player, dim_x, dim_y);
			else if (map.map[x][y] == 'C')
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, img.coin, dim_x, dim_y);
			else if (map.map[x][y] == 'E')
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, img.exit, dim_x, dim_y);
			dim_x += 32;
			y++;
		}
		dim_y += 32;
		dim_x = 0;
		x++;
		y = 0;
	}
	
}