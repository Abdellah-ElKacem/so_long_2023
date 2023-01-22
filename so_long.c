/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:14:05 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/22 16:37:14 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int main(int ac, char **av)
{
    t_connect_data *window;
    int fd;

    window = malloc(sizeof(t_connect_data));
    if (!window)
        return(0);
    window->mlx_ptr = mlx_init();
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return(-1);
    window->map[0] = ft_strdup(get_next_line(fd));
    window->map_weight = ft_strlen(window->map[0]) - 1;
    while(window->map[window->map_height])
    {
        window->map_height++;
        window->map[window->map_height] = ft_strdup(get_next_line(fd));
    }
    window->win_ptr = mlx_new_window(window->mlx_ptr, window->map_weight * 32, window->map_height * 32, "so_long");
    ft_checker(window);
    put_map(*window);
    find_player(window);
    // mlx_hook(window->win_ptr, 17, 0, ft_moves, NULL);
    mlx_key_hook(window->win_ptr, ft_moves, NULL);
    mlx_loop(window->mlx_ptr);
}