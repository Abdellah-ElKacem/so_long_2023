/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:58:13 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/31 22:42:47 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_check(t_connect_data *map, int y, int x, t_data *data)
{
	if (map->map_temp[y][x] == 'E')
		data->exit--;
	if (map->map[y][x] == 'C')
		data->coin--;
	map->map_temp[y][x] = '1';
	if (map->map_temp[y][x - 1] != '1')    // move left
		path_check(map, y, x - 1, data);
	if (map->map_temp[y + 1][x] != '1')    // move down
		path_check(map, y + 1 , x, data);
	if (map->map_temp[y][x + 1] != '1')    // move right
		path_check(map, y, x + 1, data);
	if (map->map_temp[y - 1][x] != '1')    // move up
		path_check(map, y - 1, x, data);
	if (data->coin == 0 && data->exit == 0)
		return (1);
	return (0);
}
