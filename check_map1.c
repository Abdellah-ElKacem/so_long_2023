/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:44:05 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/28 18:28:58 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (data->map[x][y] == 'E'
				|| data->map[x][y] == '1' || data->map[x][y] == '0'
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
	if (check_map_len(check) == 1)
		exit(write(1, "Error too many carac !", 23));
	if (check_map_rec(check) != 1)
		exit(write(1, "Error Map is not Rectangle !", 29));
}
