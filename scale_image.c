/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:17:26 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/27 09:18:55 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_colors(t_texture *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	return(*(unsigned int*)dst);
}

void	*image_scale_init(t_texture *image, float scale, void *mlx)
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
	return (image_scale.img);
}