/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalide_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:27:42 by tberube-          #+#    #+#             */
/*   Updated: 2022/04/28 11:15:13 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(int fd)
{
	close(fd);
	ft_putstr_fd("Map invalid", 2);
	exit(0);
}
