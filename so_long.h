/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:43:51 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/06 15:07:17 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "Get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

// #define GRID "10"
// #define VALID_SYMBOLS "PCE"

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
	int		width;
	int		height;
	char 	**map;
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


int	win_close(t_aff *key);
int	hook_win_keycode(int keycode, t_aff *key);

# define debug printf("debug\n");
#endif