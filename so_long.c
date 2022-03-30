/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:24:32 by tberube-          #+#    #+#             */
/*   Updated: 2022/03/30 14:01:52 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	Make_A_Empty_Square(t_data *data, int x, int y, int color)
{
	while (x <= 25)
	{
		my_mlx_pixel_put(data, x, y, color);
		x++;
	}
	while (y <= 25)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;	
	}
	while (x >= 5)
	{
		my_mlx_pixel_put(data, x, y, color);
		x--;
	}
	while (y >= 5)
	{
		my_mlx_pixel_put(data, x, y, color);
		y--;
	}
		
}

int	main()
{
	void 	*mlx;
	void	*mlx_win;
	t_data	image;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 600, "so_long");
	image.img = mlx_new_image(mlx, 900, 600);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	Make_A_Empty_Square(&image, 5, 5, 0x00FF0000);
	// Make_A_Empty_Square(&image, 40, 5, 0x00FF0000, 25);
	mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
	mlx_loop(mlx);
}