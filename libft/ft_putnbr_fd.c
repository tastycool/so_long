/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:59:23 by tberube-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/17 12:03:35 by tberube-         ###   ########.fr       */
=======
/*   Updated: 2021/11/01 13:14:11 by tberube-         ###   ########.fr       */
>>>>>>> f20a70b6ee8cb7e79360fd098288e1ae432eff17
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(size_t n, size_t base_len, char *base, int fd)
{
<<<<<<< HEAD
	char	c;

	if (n >= base_len)
		ft_putnbr_fd(n / base_len, base_len, base, fd);
	c = base[(n % base_len)];
	write(1, &c, 1);
}
=======
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
>>>>>>> f20a70b6ee8cb7e79360fd098288e1ae432eff17
