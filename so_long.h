/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:43:51 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/04 14:28:58 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

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

typedef struct s_aff
{
	void	*mlx;
	void	*mlx_win;
}	t_aff;

typedef struct s_perso
{
	
}	t_perso;

int	win_close(t_aff *key);
int	hook_win_keycode(int keycode, t_aff *key);

#endif