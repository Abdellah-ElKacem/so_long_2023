/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:09:49 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/03 19:13:37 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	the_exit(t_connect_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'E')
				data->exit++;
			y++;
		}
		x++;
	}
}

void	player_move(t_connect_data *data)
{
	data->player++;
	ft_printf("Moves is: [%d]\n", data->player);
}

int	ft_exie(t_connect_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	write(1, "3ayan 3ayan !\n", 15);
	exit(0);
}
