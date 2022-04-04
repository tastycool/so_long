/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:24:54 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/04 13:46:39 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// enum {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	// ON_MOUSEDOWN = 4,
// 	// ON_MOUSEUP = 5,
// 	// ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17
// };

int	win_close(t_aff *key)
{
	mlx_destroy_window(key->mlx, key->mlx_win);
	exit(0);
}

int	hook_win_close(int keycode, t_aff *key)
{
	if (keycode == 53)
	{
		mlx_destroy_window(key->mlx, key->mlx_win);
		exit (0);
	}
	return (0);
}