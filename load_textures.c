/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:04:00 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/27 09:17:41 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_on_symbol(t_game *game, t_aff *mlx)
{
	int	i;
	int	j;
	
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, game->wall.img, i * 64, j * 88);	
			else
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, game->floor.img, i * 64, j * 88);
			if (game->map[j][i] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, game->player.img, i * 64, j * 88);
			else if (game->map[j][i] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, game->collectible.img, i * 64 + 8, j * 88 + 12);
			else if (game->map[j][i] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, game->exit.img, i * 64, j * 88);
			i++;
		}
		j++;
	}
}

void	load_texture(void *mlx, char *path, t_texture *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
}

void	load_textures(void *mlx, t_game *game)
{
	load_texture(mlx,  "sprite/xpm/player.xpm", &game->player);
	load_texture(mlx,  "sprite/xpm/wall.xpm", &game->wall);
	load_texture(mlx,  "sprite/xpm/floor.xpm", &game->floor);
	load_texture(mlx,  "sprite/xpm/coffre.xpm", &game->collectible);
	load_texture(mlx,  "sprite/xpm/exit.xpm", &game->exit);
	game->player.img = image_scale_init(&game->player, 4, mlx);
	game->wall.img = image_scale_init(&game->wall, 4, mlx);
	game->floor.img = image_scale_init(&game->floor, 4, mlx);
	game->collectible.img = image_scale_init(&game->collectible, 3, mlx);
	game->exit.img = image_scale_init(&game->exit, 4, mlx);
}