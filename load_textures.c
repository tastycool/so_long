/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:04:00 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/28 11:31:48 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_coll(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->coll++;
			x++;
		}
		y++;
	}
}

int	put_image_on_symbol(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			put_image_on_screen(g, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	load_texture(void *mlx, char *path, t_texture *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, \
	&img->endian);
}

void	load_textures(void *mlx, t_game *game)
{
	load_texture(mlx, "sprite/xpm/player.xpm", &game->player);
	load_texture(mlx, "sprite/xpm/wall.xpm", &game->wall);
	load_texture(mlx, "sprite/xpm/floor.xpm", &game->floor);
	load_texture(mlx, "sprite/xpm/coffre.xpm", &game->collectible);
	find_coll(game);
	load_texture(mlx, "sprite/xpm/exit.xpm", &game->exit);
	game->player.img = image_scale_init(&game->player, 4, mlx);
	game->wall.img = image_scale_init(&game->wall, 4, mlx);
	game->floor.img = image_scale_init(&game->floor, 4, mlx);
	game->collectible.img = image_scale_init(&game->collectible, 3, mlx);
	game->exit.img = image_scale_init(&game->exit, 4, mlx);
}
