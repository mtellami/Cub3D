/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:32:12 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/13 15:26:28 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr(fd, "(null)"));
	while (*str)
		i += write(fd, str++, 1);
	return (i);
}

int	ft_putnbr(int fd, int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (ft_putstr(fd, "-2147483648"));
	else if (nbr < 0)
	{
		i += write(fd, "-", 1);
		i += ft_putnbr(fd, -nbr);
	}
	else if (nbr >= 0 && nbr <= 9)
	{
		nbr += 48;
		i += write(fd, &nbr, 1);
	}
	else
	{
		i += ft_putnbr(fd, nbr / 10);
		i += ft_putnbr(fd, nbr % 10);
	}
	return (i);
}

int	ft_print_type(int fd, char type, va_list ap)
{
	if (type == 'c')
	{
		type = va_arg(ap, int);
		return (write(fd, &type, 1));
	}
	else if (type == 's')
		return (ft_putstr(fd, va_arg(ap, char *)));
	else if (type == 'd')
		return (ft_putnbr(fd, va_arg(ap, int)));
	else
		return (write(fd, &type, 1));
}

int	ft_dprintf(int fd, char *str, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
			i += ft_print_type(fd, *(++str), ap);
		else
			i += write(fd, str, 1);
		str++;
	}
	va_end(ap);
	return (i);
}
