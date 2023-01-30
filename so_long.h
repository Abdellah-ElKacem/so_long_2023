/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:23:40 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/31 00:34:09 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_images
{
	void	*player;
	void	*player_back;
	void	*player_right;
	void	*player_left;
	void	*coin;
	void	*floor;
	void	*wall;
	void	*exit;
}	t_images;

typedef struct s_connect_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map[10000];
	int		map_height;
	int		map_weight;
	char	*map_temp[10000];
	int		map_height_temp;
	int		map_weight_temp;
	int		player_x;
	int		player_y;
	int		pl_x;
	int		pl_y;
	int		coin;
	int		player;
	int		exit;
	int		x;
	int		y;
	int		dim_x;
	int		dim_y;

}	t_connect_data;

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strchr(const char *s, char c);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void	ft_checker(t_connect_data *check);
int		ft_moves(int key, t_connect_data *data);
void	put_map_f(t_connect_data *map);
void	put_map(t_connect_data *map);
void	put_map1(t_connect_data *map);
void	put_map2(t_connect_data *map);
void	put_map3(t_connect_data *map);
int		check_wall(t_connect_data *data);
int		check_map_len(t_connect_data *data);
int		check_map_rec(t_connect_data *data);
int		check_player(t_connect_data *data);
int		check_collection(t_connect_data *data);
void	ft_next(t_connect_data *map, t_images img);
void	move_up(t_connect_data *data);
void	check_coin(t_connect_data *data);
void	the_exit(t_connect_data *data);
int		ft_exie(void);
int		ft_printf(const char *str, ...);
void	find_player(t_connect_data *data);
void	check_coin(t_connect_data *data);
void	player_move(t_connect_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		path_check(t_connect_data *map, int y, int x);

#endif