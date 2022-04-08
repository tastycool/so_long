/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:24:54 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/07 14:33:15 by tberube-         ###   ########.fr       */
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