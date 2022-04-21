/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:04:00 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/13 17:20:26 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	
	// regarder pour proteger si out of windows return rien
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_colors(t_texture *data, int x, int y)
{
	char	*dst;

	// regarder pour proteger si out of windows return noir
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	return(*(unsigned int*)dst);
}

void*	image_scale_init(t_texture *image, float scale, void *mlx)
{
	t_texture		image_scale;
	int				x;
	int				y;
	unsigned int	color;
	
	image_scale.width = image->width * scale;
	image_scale.height = image->height * scale;
	image_scale.img = mlx_new_image(mlx, image_scale.width, image_scale.height);
	image_scale.addr = mlx_get_data_addr(image_scale.img, &image_scale.bpp, &image_scale.line_length, &image_scale.endian);
	y = 0;
	while (y < (image->height * scale))
	{
		x = 0;
		while (x < (image->width * scale))
		{
			color = get_colors(image, (x / scale), (y / scale)); // vas chercher la couleur exacte du pixel de l'image de base
			my_mlx_pixel_put(&image_scale, x, y, color); //copi la couleur prise ulterieurement et la place dans la nouvelle image
			x++;
		}
		y++;	
	}
	
	// destroy old image au choix donc boolean
	return(image_scale.img);
}

void	aff_image(t_aff *mlx, t_game *img)
{
	
	void *p = image_scale_init(&img->player, 2, mlx->mlx);
	void *f = image_scale_init(&img->floor, 2.5, mlx->mlx);
	void *w = image_scale_init(&img->wall, 2, mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, f, 50, 50);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, p, 50, 50);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, w, 1, 1);
	//j:ai merder avec les struct
}


// t_texture	*tex_path(void *mlx, char *path)
// {
// 	t_texture	*img;
// 	img = ft_calloc(1, sizeof(t_texture));
// 	if (!img)
// 		return(NULL);
// 	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
// 	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,\
// 	&img->endian);
// 	return(img);
// }


// void	load_texture(t_aff *mlx, t_game *game)
// {
// 	game->tex[PLAYER] = tex_path(mlx->mlx, "sprite/xpm/player.xpm");
// 	game->tex[WALL] = tex_path(mlx->mlx, "sprite/xpm/wall.xpm");
// 	game->tex[FLOOR] = tex_path(mlx->mlx, "sprite/xpm/floor.xpm");
// 	game->tex[COLLECTIBLE] = tex_path(mlx->mlx, "sprite/xpm/coffre.xpm");
// 	game->tex[EXIT] = tex_path(mlx->mlx, "sprite/xpm/exit.xpm");
// 	aff_image(mlx, game);	
// }

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
	aff_image(mlx, game);
}