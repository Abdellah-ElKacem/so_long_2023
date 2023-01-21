#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


typedef struct s_connect_data
{
    void *mlx_ptr;
    void *win_ptr;
    char *map[10000];
    int map_height;
    int map_weight;

}   t_connect_data;

typedef struct s_position
{
    int ply_x;
    int ply_y;

}   t_position;

typedef struct s_images
{
    void    *player;
	void    *coin;
	void    *floor;
	void    *wall;
	void    *exit;
    void    *player_front;
    void    *player_back;
    void    *player_right;
    void    *player_left;
    int     player_x;
    int     player_y;
}   t_images;


char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_strchr(const char *s, char c);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void    ft_checker(t_connect_data *check);
void    put_map(t_connect_data map);
int     ft_moves(int key);


# endif