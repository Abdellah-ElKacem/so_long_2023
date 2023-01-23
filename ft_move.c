/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:48:31 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/23 21:21:10 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			}
			y++;
		}
		x++;
	}
}
void	check_coin(t_connect_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'C')
				data->coin++;
			y++;
		}
		x++;
	}
	
}

void move_up(t_connect_data *data)
{
	t_images img;
	int dim;

	img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &dim, &dim);
	img.player_back = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_back.xpm", &dim, &dim);
    if (data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
	{
    	if (data->map[data->player_y - 1][data->player_x] == 'C')
		{
			data->map[data->player_y - 1][data->player_x] = '0';
			data->coin -= 1;
			printf("%d\n", data->coin);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.floor, data->player_x * 32, data->player_y * 32);
		data->player_y -= 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.player_back, data->player_x * 32, data->player_y * 32);
	}
	else if (data->coin == 0 && data->map[data->player_y - 1][data->player_x] == 'E')
		exit(write(1, "You Win GG !", 13));
}

void move_down(t_connect_data *data)
{
	t_images img;
	int dim;

	img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &dim, &dim);
	img.player = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player.xpm", &dim, &dim);
    if (data->map[data->player_y + 1][data->player_x] != '1' && data->map[data->player_y + 1][data->player_x] != 'E')
	{
    	if (data->map[data->player_y + 1][data->player_x] == 'C')
		{
			data->map[data->player_y + 1][data->player_x] = '0';
			data->coin -= 1;
			printf("%d\n", data->coin);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.floor, data->player_x * 32, data->player_y * 32);
		data->player_y += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.player, data->player_x * 32, data->player_y * 32);
	}
	else if (data->coin == 0 && data->map[data->player_y + 1][data->player_x] == 'E')
		exit(write(1, "You Win GG !", 13));
}

void move_right(t_connect_data *data)
{
	t_images img;
	int dim;

	img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &dim, &dim);
	img.player_right = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_right.xpm", &dim, &dim);
    if (data->map[data->player_y][data->player_x + 1] != '1' && data->map[data->player_y][data->player_x + 1] != 'E')
	{
		if (data->map[data->player_y][data->player_x + 1] == 'C')
		{
			data->map[data->player_y][data->player_x + 1] = '0';
			data->coin -= 1;
			printf("%d\n", data->coin);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.floor, data->player_x * 32, data->player_y * 32);
		data->player_x += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.player_right, data->player_x * 32, data->player_y * 32);
	}
	else if (data->coin == 0 && data->map[data->player_y][data->player_x + 1] == 'E')
		exit(write(1, "You Win GG !", 13));
}

void move_left(t_connect_data *data)
{
	t_images img;
	int dim;

	img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &dim, &dim);
	img.player_left = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_left.xpm", &dim, &dim);
    if (data->map[data->player_y][data->player_x - 1] != '1' && data->map[data->player_y][data->player_x - 1] != 'E')
	{
    	if (data->map[data->player_y][data->player_x - 1] == 'C')
		{
			data->map[data->player_y][data->player_x - 1] = '0';
			data->coin -= 1;
			printf("%d\n", data->coin);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.floor, data->player_x * 32, data->player_y * 32);
		data->player_x -= 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.player_left, data->player_x * 32, data->player_y * 32);
	}
	else if (data->coin == 0 && data->map[data->player_y][data->player_x - 1] == 'E')
		exit(write(1, "You Win GG !", 13));
}

int ft_moves(int key, t_connect_data *data)
{
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
	return (0);
}
