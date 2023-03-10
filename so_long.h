/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:23:40 by ael-kace          #+#    #+#             */
/*   Updated: 2023/02/03 20:00:24 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_images
{
	void	*player;
	void	*player_back;
	void	*player_rt;
	void	*plr_lt;
	void	*coin;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*exit_o;
}	t_images;

typedef struct data
{
	int	coin;
	int	exit;
}	t_data;

typedef struct s_connect_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			map_height;
	int			map_weight;
	int			player_x;
	int			player_y;
	int			coin;
	int			player;
	int			exit;
	int			x;
	int			y;
	int			dim_x;
	int			dim_y;
	char		*map[100000];
	char		*map_temp[100000];
	char		*map_temp_e[100000];
	t_images	imgs;
}	t_connect_data;

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strchr(const char *s, char c);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void	ft_checker(t_connect_data *check);
int		ft_moves(int key, t_connect_data *data);
void	creat_imgs(t_connect_data *map);
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
void	move_up(t_connect_data *data);
void	see_down_coin(t_connect_data *data);
void	see_down_else(t_connect_data *data);
void	see_left_coin(t_connect_data *data);
void	move_down(t_connect_data *data);
void	move_right(t_connect_data *data);
void	check_coin(t_connect_data *data);
void	the_exit(t_connect_data *data);
int		ft_exie(t_connect_data *data);
int		ft_printf(const char *str, ...);
void	find_player(t_connect_data *data);
void	check_coin(t_connect_data *data);
void	player_move(t_connect_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		path_check(t_connect_data *map, int y, int x, t_data *data);
int		path_check_e(t_connect_data *map, int y, int x, t_data *data);

#endif