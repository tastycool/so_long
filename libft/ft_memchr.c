/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:00 by tberube-          #+#    #+#             */
/*   Updated: 2021/10/07 11:32:36 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*o_s;
	unsigned char	o_c;
	size_t			i;

	o_s = (unsigned char *)s;
	o_c = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (*o_s == o_c)
			return (o_s);
		o_s++;
	}
	return (0);
}
