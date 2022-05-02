/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:32:12 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/28 14:50:27 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_dimension(t_putContente *contente, int fd)
{
	char			*str;
	char			*tmp;

	contente->height_grid = 1;
	str = get_next_line(fd);
	tmp = ft_strtrim(str, "\n");
	free(str);
	contente->width_grid = ft_strlen(tmp);
	free(tmp);
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		contente->height_grid++;
		free(str);
	}	
}

void	mapping_length(int fd, t_putContente *contente, char *map_file)
{
	map_dimension(contente, fd);
	if (!fd)
		quit(fd);
	contente->map = (char **)ft_calloc(contente->height_grid + 1, \
	sizeof(char *));
	if (contente->map == NULL)
		quit(fd);
	close(fd);
	fd = open(map_file, O_RDONLY);
	valid_check(fd, contente);
}
