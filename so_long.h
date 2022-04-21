/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:43:51 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/13 17:15:42 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include "GNL/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

#define GRID '1'
#define VALID_SYMBOLS "PCE10"

typedef struct s_texture 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_texture;


typedef	struct s_putContente
{
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
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_aff;

typedef struct s_movement
{
	int	escape;
	int	w;
	int	a;
	int	s;
	int	d;
	
}	t_movement;


typedef enum keypress {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	// ON_MOUSEDOWN = 4,
	// ON_MOUSEUP = 5,
	// ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	keypress;

// typedef enum game_tex
// {
// 	PLAYER,
// 	WALL,
// 	FLOOR,
// 	COLLECTIBLE,
// 	EXIT,	
// } game_tex;

typedef struct s_game
{
	t_texture 		img;
	t_texture 		floor;
	t_texture 		player;
	t_texture		wall;
	t_texture		collectible;
	t_texture		exit;
	char 			**map;
	
} t_game;


void			check_grid1(int fd, t_putContente *contente);
void			check_grid2(int fd, t_putContente *contente);
void			check_grid3(int fd, t_putContente *contente);
void			check_grid4(int fd, t_putContente *contente);
//void			keycode_init(t_perso *move);
int				win_close(t_aff *mlx, t_game *game);
int				hook_win_close(int keycode);
void			quit(int fd);
void			doublon_check(int fd, t_putContente *contente);
void			check_grid(int fd, t_putContente *contente);
void			check_symbol(int fd, t_putContente *contente);
void			valid_check(int fd, t_putContente *contente);
void			mapping_length(int fd, t_putContente *contente, char *map_file);
void			dup_map(char **src, char **dest);
void			load_textures(void *mlx, t_game *game);
void			mlx_close(t_aff	*mlx);

void			aff_image(t_aff *mlx, t_game *img);
void			*image_scale_init(t_texture *image, float scale, void *mlx);
unsigned int	get_colors(t_texture *data, int x, int y);
void			my_mlx_pixel_put(t_texture *data, int x, int y, int color);
# define debug printf("debug\n");
#endif