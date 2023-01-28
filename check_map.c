/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:41:14 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/27 13:43:49 by ael-kace         ###   ########.fr       */
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

int	check_map_len(t_connect_data *data)
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
		return (1);
	return (0);
}

int	check_map_rec(t_connect_data *data)
{
	int	x;

	x = data->map_height - 1;
	if (ft_strlen(data->map[x]) != data->map_height)
		return (1);
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
