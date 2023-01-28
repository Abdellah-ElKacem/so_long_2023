/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:14:05 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/28 18:41:42 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	create_map(t_connect_data *window, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	window->map[0] = get_next_line(fd);
	window->map_weight = ft_strlen(window->map[0]) - 1;
	while (window->map[window->map_height])
	{
		window->map_height++;
		window->map[window->map_height] = get_next_line(fd);
	}
	return (1);
}

void	the_checker(t_connect_data *window)
{
	ft_checker(window);
	put_map_f(window);
	put_map(window);
	put_map1(window);
	put_map2(window);
	put_map3(window);
	check_coin(window);
}

int	main(int ac, char **av)
{
	t_connect_data	*window;

	if (ac != 2)
		exit(write(1, "Error Check Arguments !\n", 25));
	window = malloc(sizeof(t_connect_data));
	if (!window)
		return (0);
	window->mlx_ptr = mlx_init();
	create_map(window, av);
	window->win_ptr = mlx_new_window(window->mlx_ptr \
		, window->map_weight * 32, window->map_height * 32, "so_long");
	the_checker(window);
	mlx_hook(window->win_ptr, 17, 0, ft_exie, NULL);
	mlx_hook(window->win_ptr, 2, 0, ft_moves, window);
	mlx_loop(window->mlx_ptr);
}
