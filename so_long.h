/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:43:51 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/08 11:02:24 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "GNL/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

#define GRID '1'
#define VALID_SYMBOLS "PCE10"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_data;

typedef	struct s_putContente
{
	void	*image_player;
	void	*image_floor;
	void	*image_wall;	
	void	*image_collectible;
	void	*image_exit;
	int		pos_x;
	int		pos_y;
	int		width_grid;
	int		height_grid;
	char 	**map;
	int		i;
	int		j;
} t_putContente;

typedef struct s_aff
{
	void	*mlx;
	void	*mlx_win;
}	t_aff;

typedef struct s_movement
{
	int	escape;
	int	w;
	int	a;
	int	s;
	int	d;
	
}	t_movement;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	// ON_MOUSEDOWN = 4,
	// ON_MOUSEUP = 5,
	// ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


void			check_grid1(int fd, t_putContente *contente);
void			check_grid2(int fd, t_putContente *contente);
void			check_grid3(int fd, t_putContente *contente);
void			check_grid4(int fd, t_putContente *contente);
//void			keycode_init(t_perso *move);
int				win_close(t_aff *key);
int				hook_win_close(int keycode, t_aff *key);
void			quit(int fd);
void			doublon_check(int fd, t_putContente *contente);
void			check_grid(int fd, t_putContente *contente);
void			check_symbol(int fd, t_putContente *contente);
void			valid_check(int fd, t_putContente *contente);
void			mapping_length(int fd, t_putContente *contente, char *map_file);
void			aff_image(t_aff mlx, t_data img, t_putContente sprite);
t_data			image_scale_init(t_data *image, float scale, void *mlx);
unsigned int	get_colors(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
# define debug printf("debug\n");
#endif