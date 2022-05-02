/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:24:54 by tberube-          #+#    #+#             */
/*   Updated: 2022/05/02 09:36:39 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook_move(int keycode, t_game *game)
{
	find_p(game);
	if (keycode == 53)
		win_close(game);
	if (keycode == 0)
		left_move(game);
	if (keycode == 1)
		down_move(game);
	if (keycode == 2)
		right_move(game);
	if (keycode == 13)
		top_move(game);
	return (0);
}

int	win_close(void)
{
	exit (0);
	return (0);
}

void	mlx_close(t_aff	*mlx, t_game *game)
{
	mlx_hook(mlx->mlx_win, 2, 0, key_hook_move, game);
	mlx_hook(mlx->mlx_win, ON_DESTROY, 0, win_close, mlx);
}
