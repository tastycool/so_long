/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:24:32 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/04 14:29:12 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	
	// regarder pour proteger si out of windows return rien
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_colors(t_data *data, int x, int y)
{
	char	*dst;

	// regarder pour proteger si out of windows return noir
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return(*(unsigned int*)dst);
}

t_data	image_scale_init(t_data *image, float scale, void *mlx)
{
	t_data			image_scale;
	float			x;
	float			y;
	unsigned int	color;
	
	image_scale.width = image->width * scale;
	image_scale.height = image->height * scale;
	image_scale.img = mlx_new_image(mlx, image_scale.width, image_scale.height);
	image_scale.addr = mlx_get_data_addr(image_scale.img, &image_scale.bits_per_pixel, &image_scale.line_length, &image_scale.endian);
	x = 0;
	while (x < (image->width * scale))
	{
		y = 0;
		while (y < (image->height * scale))
		{
			color = get_colors(image, (x / scale), (y / scale)); // vas chercher la couleur exacte du pixel de l'image de base
			my_mlx_pixel_put(&image_scale, x, y, color); //copi la couleur prise ulterieurement et la place dans la nouvelle image
			y++;	
		}
		x++;
	}
	// destroy old image au choix donc boolean
	return(image_scale);
}

// void	init_image()
// {
// 	//
// }

void	aff_image(t_aff mlx, t_data img)
{
	t_data	image_player;
	t_data	image_floor;
	t_data	image_murs;
	
	image_player.img = mlx_xpm_file_to_image(mlx.mlx, "sprite/xpm/player.xpm", &image_player.width, &image_player.height);
	image_floor.img = mlx_xpm_file_to_image(mlx.mlx, "sprite/xpm/floor.xpm", &image_floor.width, &image_floor.height);
	image_murs.img = mlx_xpm_file_to_image(mlx.mlx, "sprite/xpm/murs.xpm", &image_murs.width, &image_murs.height);
	image_player.addr = mlx_get_data_addr(image_player.img, &image_player.bits_per_pixel, &image_player.line_length, &image_player.endian);
	image_floor.addr = mlx_get_data_addr(image_floor.img, &image_floor.bits_per_pixel, &image_floor.line_length, &image_floor.endian);
	image_murs.addr = mlx_get_data_addr(image_murs.img, &image_murs.bits_per_pixel, &image_murs.line_length, &image_murs.endian);
	image_player = image_scale_init(&image_player, 2, mlx.mlx);
	image_floor = image_scale_init(&image_floor, 2.5, mlx.mlx);
	image_murs = image_scale_init(&image_murs, 2, mlx.mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, image_floor.img, 50, 50);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, image_player.img, 50, 50);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, image_murs.img, 1, 1);
}

int	main()
{
	t_aff	mlx;
	t_data	image;
	void	*player;
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 600, 600, "so_long");
	image.img = mlx_new_image(mlx.mlx, 600, 600);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	aff_image(mlx, image);
	mlx_hook(mlx.mlx_win, 17, 0L, win_close, &mlx);
	mlx_key_hook(mlx.mlx_win, hook_win_keycode, &mlx);
	mlx_loop(mlx.mlx);
	//try
	//structure pour le scale
	//fonction pour scale
}