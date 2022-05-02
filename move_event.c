/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:51:51 by tberube-          #+#    #+#             */
/*   Updated: 2022/05/02 09:38:49 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	minus_col(t_game *game)
{
	game->coll--;
}

void	exit_map(t_game *game)
{
	if (game->coll == 0)
		win_close();
}
