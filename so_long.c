/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:24:32 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/13 16:53:52 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
// {
// 	char	*dst;

	
// 	// regarder pour proteger si out of windows return rien
// 	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// unsigned int	get_colors(t_texture *data, int x, int y)
// {
// 	char	*dst;

// 	// regarder pour proteger si out of windows return noir
// 	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
// 	return(*(unsigned int*)dst);
// }

// t_texture	image_scale_init(t_texture *image, float scale, void *mlx)
// {
// 	t_texture		image_scale;
// 	float			x;
// 	float			y;
// 	unsigned int	color;
	
// 	image_scale.width = image->width * scale;
// 	image_scale.height = image->height * scale;
// 	image_scale.img = mlx_new_image(mlx, image_scale.width, image_scale.height);
// 	image_scale.addr = mlx_get_data_addr(image_scale.img, &image_scale.bpp, &image_scale.line_length, &image_scale.endian);
// 	x = 0;
// 	while (x < (image->width * scale))
// 	{
// 		y = 0;
// 		while (y < (image->height * scale))
// 		{
// 			color = get_colors(image, (x / scale), (y / scale)); // vas chercher la couleur exacte du pixel de l'image de base
// 			my_mlx_pixel_put(&image_scale, x, y, color); //copi la couleur prise ulterieurement et la place dans la nouvelle image
// 			y++;	
// 		}
// 		x++;
// 	}
// 	// destroy old image au choix donc boolean
// 	return(image_scale);
// }


int main(int argc, char **argv)
{
	(void)argc;
	t_game 	game;
	t_aff	mlx;
	//int				keycode;
	t_putContente 	contente;
	//t_data			img;
	//t_aff			mlx;
	int fd;
	
	//keycode = 0;
	mlx.mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	mapping_length(fd, &contente, argv[1]);
	game.map = (char **)ft_calloc(contente.height_grid + 1, sizeof(char *));
	dup_map(contente.map, game.map);
	//load_texture(&mlx, &game);
	
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1920, 1080, "so_long");
	
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_length, &mlx.endian);
	load_textures(mlx.mlx, &game);
	//mlx_hook(mlx.mlx_win , 2, 0, hook_win_close, &mlx);
	mlx_close(&mlx);
	// hook_win_close(keycode, mlx.mlx);
	// win_close(mlx.mlx_win);
	//aff_image(mlx, img);
	mlx_loop(mlx.mlx);
}