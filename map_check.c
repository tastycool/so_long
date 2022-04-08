/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:32:12 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/08 11:30:59 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	doublon_check(int fd, t_putContente *contente)
{
	int	P;
	int	E;
	
	contente->i = 0;
	contente->j = 0;
	P = 0;
	E = 0;
	while (contente->map[contente->j])
	{
		if (E > 1 || P > 1)
			quit(fd);
		if (contente->map[contente->j][contente->i] == 'P')
			P++;
		if (contente->map[contente->j][contente->i] == 'E')
			E++;
	 	if (contente->map[contente->j][contente->i] == '\0')
		{
			contente->j++;
			contente->i = 0;
		}
	 	else
			contente->i++;
	}
	check_grid(fd, contente);

	
	//check ton contoure de map
	//check les doublon de symbole P et E et compte les C (collectible)/struct
}

void	check_grid(int fd, t_putContente *contente)
{
	contente->i = 0;
	contente->j = 0;
	check_grid1(fd, contente);
	check_grid2(fd, contente);
	check_grid3(fd, contente);
	check_grid4(fd, contente);
	//check ton contoure de map
	//est ce que la map est carré ou rectangle
	//est ce que ma premiere et derniere ligne son des 1
	//est de que ma premiere et derniere lettre de ma str est bien 1
}

void	check_symbol(int fd, t_putContente *contente)
{
	
	contente->j = 0;
	while (contente->map[contente->j])
	{
		contente->i = 0;
		while (contente->map[contente->j][contente->i] != '\0')
		{
			if(!ft_strchr(VALID_SYMBOLS, contente->map[contente->j][contente->i]))
				quit(fd);
			contente->i++;
		}
		if (contente->i < contente->width_grid || contente->i > contente->width_grid)
			quit(fd);
		contente->j++;
	}
	doublon_check(fd, contente);
}

void	valid_check(int fd, t_putContente *contente)
{
	char	*str;
	
	// str = get_next_line(fd);
	// contente->j = 0;
	// contente->map[contente->j] = ft_strtrim(str, "\n");
	// free(str);
	// contente->j++;
	while(contente->j <= contente->height_grid)
	{
		str = get_next_line(fd);
		contente->map[contente->j] = ft_strtrim(str, "\n");
		free(str);
		if (contente->map[contente->j] == NULL)
			quit(fd);
		contente->j++;
	}
	// contente->map[contente->j - 1][contente->width_grid - 1] = '\n';
	// contente->map[contente->j - 1][contente->width_grid] = '\0';
	check_symbol(fd, contente);	
}