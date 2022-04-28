/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:32:12 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/28 11:35:32 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	doublon_check(int fd, t_putContente *contente)
{
	int	p;
	int	e;

	contente->j = 0;
	p = 0;
	e = 0;
	while (contente->map[contente->j])
	{	
		contente->i = 0;
		while (contente->map[contente->j][contente->i])
		{
			if (contente->map[contente->j][contente->i] == 'P')
				p++;
			else if (contente->map[contente->j][contente->i] == 'E')
				e++;
			contente->i++;
		}
		contente->j++;
	}
	if (e != 1 || p != 1)
		quit(fd);
	check_grid(fd, contente);
}

void	check_grid(int fd, t_putContente *contente)
{
	contente->i = 0;
	contente->j = 0;
	check_grid1(fd, contente);
	check_grid2(fd, contente);
	check_grid3(fd, contente);
	check_grid4(fd, contente);
}

void	check_symbol(int fd, t_putContente *contente)
{
	contente->j = 0;
	while (contente->map[contente->j])
	{
		contente->i = 0;
		while (contente->map[contente->j][contente->i] != '\0')
		{
			if (!ft_strchr(VALID_SYMBOLS, \
			contente->map[contente->j][contente->i]))
				quit(fd);
			contente->i++;
		}
		if (contente->i < contente->width_grid || \
		contente->i > contente->width_grid)
			quit(fd);
		contente->j++;
	}
	doublon_check(fd, contente);
}

void	valid_check(int fd, t_putContente *contente)
{
	char	*str;

	contente->j = 0;
	while (contente->j < contente->height_grid)
	{
		str = get_next_line(fd);
		contente->map[contente->j] = ft_strtrim(str, "\n");
		free(str);
		if (contente->map[contente->j] == NULL)
			quit(fd);
		contente->j++;
	}
	check_symbol(fd, contente);
}
