/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:32:12 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/06 15:37:02 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_grid(char map, bool check, t_data *data)
{
	int i;
	
	i = 0;
	
	//check ton contoure de map
	//est ce que la map est carré ou rectangle
	//est ce que ma premiere et derniere ligne son des 1
	//est de que ma premiere et derniere lettre de ma str est bien 1
}

bool	check_symbol(char map, bool check, t_data *data)
{
	//static int no_double; pour le P et pour le E
	//check les doublon de symbole P et E et compte les C (collectible)/struct
}

void	valid_check(int fd, t_data *data, t_putContente *contente)
{
	bool	check;
	char	*str;
	int		i;
	
	
	check = true;
	i = 0;
	while(contente->map[i])
	{
		contente->map[i] = get_next_line(fd);
		i++;
	}
	check_symbol(contente->map, check, data);
	if (check == false);
		ft_putstr_fd("Map invalid", 2);
	
}

void	mapping_length(int fd, t_data *data)
{
	t_putContente	*check_map;
	int				i;
	
	
	data->width = ft_strlen(get_next_line(fd));
	while(get_next_line(fd) != NULL)
	{
		data->height++;
		debug;
	}
	data->height++;
	check_map = malloc(sizeof(t_putContente));
	check_map->map = (char **)malloc((data->height + 1) * (sizeof(char *)));
	close(fd);
	valid_check(fd, data, check_map);
	affichage(data);
}

void	affichage(t_data *data)
{
	t_aff	*mlx;
	void	*player;
	
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 600, 600, "so_long");
	data->img = mlx_new_image(mlx->mlx, 600, 600);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	aff_image(mlx, data);
	mlx_hook(mlx->mlx_win, 17, 0L, win_close, &mlx);
	mlx_key_hook(mlx->mlx_win, hook_win_keycode, &mlx);
	mlx_loop(mlx->mlx);
}

int main(int argc, char **argv)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	mapping_length(open(argv[1], O_RDONLY), data);
}