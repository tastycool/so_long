/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:24:32 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/01 09:22:27 by tberube-         ###   ########.fr       */
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


// void	Make_A_Empty_Square(t_data *data, int x, int y, int color)
// {
// 	while (x <= 25)
// 	{
// 		my_mlx_pixel_put(data, x, y, color);
// 		x++;
// 	}
// 	while (y <= 25)
// 	{
// 		my_mlx_pixel_put(data, x, y, color);
// 		y++;	
// 	}
// 	while (x >= 5)
// 	{
// 		my_mlx_pixel_put(data, x, y, color);
// 		x--;
// 	}
// 	while (y >= 5)
// 	{
// 		my_mlx_pixel_put(data, x, y, color);
// 		y--;
// 	}
		
// }

int	close(int keycode, t_aff *key)
{
	mlx_destroy_window(key->mlx, key->mlx_win);
	return(0);
}

int	main()
{
	t_aff	mlx;
	t_data	image;
	void	*player;
	t_data	image_player;
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 600, 600, "so_long");
	image.img = mlx_new_image(mlx.mlx, 600, 600);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	//Make_A_Empty_Square(&image, 5, 5, 0x00FF0000);
	image_player.img = mlx_xpm_file_to_image(mlx.mlx, "sprite/xpm/player.xpm", &image_player.width, &image_player.height);
	image_player.addr = mlx_get_data_addr(image_player.img, &image_player.bits_per_pixel, &image_player.line_length, &image_player.endian);
	image_player = image_scale_init(&image_player, 2, mlx.mlx);
	// image_player = image_scale_init(&image_player, 1, mlx);
	//image_player = image_scale_init(&image_player, , mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, image.img, 0, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, image_player.img, 50, 50);
	//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, image_scale_init(&image_player, 2, mlx.mlx).img, 100, 100);
	mlx_hook(mlx.mlx_win, 2, 1L<<0, close, &mlx);
	mlx_loop(mlx.mlx);
	//try
	//structure pour le scale
	//fonction pour scale
}