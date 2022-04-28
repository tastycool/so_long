/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:22:36 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/28 11:42:55 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_on_screen(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx->mlx, g->mlx->mlx_win, \
		g->wall.img, x * 64, y * 88);
	else
		mlx_put_image_to_window(g->mlx->mlx, g->mlx->mlx_win, \
		g->floor.img, x * 64, y * 88);
	if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx->mlx, g->mlx->mlx_win, \
		g->player.img, x * 64, y * 88);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx->mlx, g->mlx->mlx_win, \
		g->collectible.img, x * 64 + 8, y * 88 + 12);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx->mlx, g->mlx->mlx_win, \
		g->exit.img, x * 64, y * 88);
}
