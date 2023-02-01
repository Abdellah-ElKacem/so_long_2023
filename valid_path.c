/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:58:13 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/01 17:31:50 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_check(t_connect_data *map, int y, int x, t_data *data)
{
	if (map->map[y][x] == 'C')
		data->coin--;
	map->map_temp[y][x] = '1';
	if (map->map_temp[y][x - 1] != '1' && map->map_temp[y][x - 1] != 'E')
		path_check(map, y, x - 1, data);
	if (map->map_temp[y + 1][x] != '1' && map->map_temp[y + 1][x] != 'E')
		path_check(map, y + 1, x, data);
	if (map->map_temp[y][x + 1] != '1' && map->map_temp[y][x + 1] != 'E')
		path_check(map, y, x + 1, data);
	if (map->map_temp[y - 1][x] != '1' && map->map_temp[y - 1][x] != 'E')
		path_check(map, y - 1, x, data);
	if (data->coin == 0)
		return (1);
	return (0);
}

int	path_check_e(t_connect_data *map, int y, int x, t_data *data)
{
	if (map->map_temp_e[y][x] == 'E')
		data->exit--;
	map->map_temp_e[y][x] = '1';
	if (map->map_temp_e[y][x - 1] != '1')
		path_check_e(map, y, x - 1, data);
	if (map->map_temp_e[y + 1][x] != '1')
		path_check_e(map, y + 1, x, data);
	if (map->map_temp_e[y][x + 1] != '1')
		path_check_e(map, y, x + 1, data);
	if (map->map_temp_e[y - 1][x] != '1')
		path_check_e(map, y - 1, x, data);
	if (data->exit == 0)
		return (1);
	return (0);
}
