/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:46:00 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/28 11:42:22 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_p(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->coord.x = x;
				game->coord.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	left_move(t_game *game)
{
	bool	is_no_wall;
	char	check;

	is_no_wall = false;
	check = game->map[game->coord.y][game->coord.x - 1];
	if (check == 'C' || check == '0')
		is_no_wall = true;
	if (check == 'C')
		minus_col(game);
	if (check == 'E')
		exit_map(game);
	if (is_no_wall == true)
	{
		if (check == 'C' || check == '0')
		{
			game->map[game->coord.y][game->coord.x] = '0';
			game->map[game->coord.y][game->coord.x - 1] = 'P';
		}
		game->nb_move++;
		ft_putnbr_fd(game->nb_move, BASE_10, BASE_DEC, 1);
		printf("%c", '\n');
	}
}

void	down_move(t_game *game)
{
	bool	is_no_wall;
	char	check;

	is_no_wall = false;
	check = game->map[game->coord.y + 1][game->coord.x];
	if (check == 'C' || check == '0')
		is_no_wall = true;
	if (check == 'C')
		minus_col(game);
	if (check == 'E')
		exit_map(game);
	if (is_no_wall == true)
	{
		if (check == 'C' || check == '0')
		{
			game->map[game->coord.y][game->coord.x] = '0';
			game->map[game->coord.y + 1][game->coord.x] = 'P';
		}
		game->nb_move++;
		ft_putnbr_fd(game->nb_move, BASE_10, BASE_DEC, 1);
		printf("%c", '\n');
	}
}

void	right_move(t_game *game)
{
	bool	is_no_wall;
	char	check;

	is_no_wall = false;
	check = game->map[game->coord.y][game->coord.x + 1];
	if (check == 'C' || check == '0')
		is_no_wall = true;
	if (check == 'C')
		minus_col(game);
	if (check == 'E')
		exit_map(game);
	if (is_no_wall == true)
	{
		if (check == 'C' || check == '0')
		{
			game->map[game->coord.y][game->coord.x] = '0';
			game->map[game->coord.y][game->coord.x + 1] = 'P';
		}
		game->nb_move++;
		ft_putnbr_fd(game->nb_move, BASE_10, BASE_DEC, 1);
		printf("%c", '\n');
	}
}

void	top_move(t_game *game)
{
	bool	is_no_wall;
	char	check;

	is_no_wall = false;
	check = game->map[game->coord.y - 1][game->coord.x];
	if (check == 'C' || check == '0')
		is_no_wall = true;
	if (check == 'C')
		minus_col(game);
	if (check == 'E')
		exit_map(game);
	if (is_no_wall == true)
	{
		if (check == 'C' || check == '0')
		{
			game->map[game->coord.y][game->coord.x] = '0';
			game->map[game->coord.y - 1][game->coord.x] = 'P';
		}
		game->nb_move++;
		ft_putnbr_fd(game->nb_move, BASE_10, BASE_DEC, 1);
		printf("%c", '\n');
	}	
}
