/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:32:12 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/12 16:23:13 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapping_length(int fd, t_putContente *contente, char *map_file)
{
	//t_data			*data;
	char			*str;
	char			*tmp;
	contente->height_grid = 1;
	str = get_next_line(fd);
	tmp = ft_strtrim(str, "\n");
	free(str);
	contente->width_grid = ft_strlen(tmp);
	free(tmp);
	while(get_next_line(fd) != NULL)
		contente->height_grid++;
	if (!fd)
		quit(fd);
	contente->map = (char **)ft_calloc(contente->height_grid + 1, sizeof(char *));
	if (contente->map == NULL)
		quit(fd);
	close(fd);
	fd = open(map_file, O_RDONLY);
	valid_check(fd, contente);
//	data = malloc(sizeof(t_data));
	//affichage(data);
}

// void	affichage(t_data *data)
// {
// 	t_aff	*mlx;
// 	void	*player;
	
// 	mlx->mlx = mlx_init();
// 	mlx->mlx_win = mlx_new_window(mlx->mlx, 600, 600, "so_long");
// 	data->img = mlx_new_image(mlx->mlx, 600, 600);
// 	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
// 	aff_image(mlx, data);
// 	mlx_hook(mlx->mlx_win, 17, 0L, win_close, &mlx);
// 	mlx_key_hook(mlx->mlx_win, hook_win_keycode, &mlx);
// 	mlx_loop(mlx->mlx);
// }
