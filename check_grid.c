/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:04:42 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/08 11:55:23 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	check_grid1(int fd, t_putContente *contente)
{
	while (contente->i < contente->width_grid)
	{
		if (contente->map[contente->j][contente->i] != GRID)
			quit(fd);
		contente->i++;
	}
}

void	check_grid2(int fd, t_putContente *contente)
{
	contente->i -= 1;
	while (contente->j < contente->height_grid)
	{
		contente->j++;
		if (contente->map[contente->j][contente->i] != GRID)
			quit(fd);
	}	
}

void	check_grid3(int fd, t_putContente *contente)
{
	while (contente->i > 0)
	{
		contente->i--;
		if (contente->map[contente->j][contente->i] != GRID)
			quit(fd);
	}
}

void	check_grid4(int fd, t_putContente *contente)
{
	while (contente->j > 0)
	{
		contente->j--;
		if (contente->map[contente->j][contente->i] != GRID)
			quit(fd);
	}
}