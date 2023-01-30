/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:58:13 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/31 00:45:50 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_check(t_connect_data *map, int y, int x)
{
	if (map->map[y][x] == 'C')
		map->coin--;
	if (map->map[y][x] == 'E')
		map->exit--;
	map->map[y][x] = '1';
	if (map->map[y][x - 1] != '1')// move left
		path_check(map, y, x - 1);
	if (map->map[y + 1][x] != '1')// move down
		path_check(map, y + 1 , x);
	if (map->map[y][x + 1] != '1')// move right
		path_check(map, y, x + 1);
	if (map->map[y - 1][x] != '1')// move up
		path_check(map, y - 1, x);
	if (map->coin == 0 && map->exit == 0)
		return (1);
	return (0);
}
