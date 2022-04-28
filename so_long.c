/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:24:32 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/28 13:32:01 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game			game;
	t_aff			mlx;
	t_putContente	contente;
	int				fd;

	(void)argc;
	mlx.mlx = mlx_init();
	game.mlx = &mlx;
	fd = open(argv[1], O_RDONLY);
	mapping_length(fd, &contente, argv[1]);
	game.map = (char **)ft_calloc(contente.height_grid + 1, sizeof(char *));
	dup_map(contente.map, game.map);
	mlx.mlx_win = mlx_new_window(mlx.mlx, contente.width_grid * 64, \
	contente.height_grid * 88, "so_long");
	mlx.img = mlx_new_image(mlx.mlx, contente.width_grid * 64, \
	contente.height_grid * 88);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_length, \
	&mlx.endian);
	load_textures(mlx.mlx, &game);
	mlx_close(&mlx, &game);
	mlx_loop_hook(game.mlx->mlx, put_image_on_symbol, &game);
	mlx_loop(mlx.mlx);
}
