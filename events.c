/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:24:54 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/13 16:17:01 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	keycode_init(t_perso *move)
// {
// 	move->escape = 53;
// 	move->a = 0;
// 	move->s = 1;
// 	move->d = 2;
// 	move->w = 13;
// }

int	win_close(t_aff *mlx, t_game *game)
{
	mlx_destroy_image(mlx->mlx, game->floor.img);
	exit(0);
}

int	hook_win_close(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

void	mlx_close(t_aff	*mlx)
{
	mlx_hook(mlx->mlx_win , 2, 1L<<0, hook_win_close, &mlx);
	mlx_hook(mlx->mlx_win , ON_DESTROY, 0, win_close, &mlx);
}