/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:14:05 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/01 17:28:22 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_map(t_connect_data *window, char **av)
{
	int		fd;
	char	*readd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	readd = get_next_line(fd);
	window->map_weight = ft_strlen(readd) - 1;
	while (readd)
	{
		window->map[window->map_height] = ft_strdup(readd);
		window->map_temp[window->map_height] = ft_strdup(readd);
		window->map_temp_e[window->map_height] = ft_strdup(readd);
		window->map_height++;
		free(readd);
		readd = get_next_line(fd);
	}
	return (1);
}

void	the_checker(t_connect_data *window)
{
	ft_checker(window);
	put_map_f(window);
	put_map1(window);
	put_map(window);
	put_map2(window);
	put_map3(window);
	check_coin(window);
	the_exit(window);
}

void	error_path(t_connect_data *window)
{
	t_data	data;

	data.coin = window->coin;
	data.exit = window->exit;
	if (!path_check(window, window->player_y, window->player_x, &data)
		|| !path_check_e(window, window->player_y, window->player_x, &data))
		exit (write(1, "Error : Check-Path failed\n", 27));
}

int	main(int ac, char **av)
{
	t_connect_data	*window;

	if (ac != 2)
		exit(write(1, "Error Check Arguments !\n", 25));
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		exit(write(1, "Error Check Extentions !\n", 26));
	window = malloc(sizeof(t_connect_data));
	if (!window)
		return (0);
	window->mlx_ptr = mlx_init();
	create_map(window, av);
	window->win_ptr = mlx_new_window(window->mlx_ptr \
		, window->map_weight * 32, window->map_height * 32, "so_long");
	the_checker(window);
	error_path(window);
	write(1, "\n\n!--- Welcome to the Game---!\n\n", 32);
	mlx_hook(window->win_ptr, 17, 0, ft_exie, NULL);
	mlx_hook(window->win_ptr, 2, 0, ft_moves, window);
	mlx_loop(window->mlx_ptr);
}
