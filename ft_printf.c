/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:15:29 by ael-kace          #+#    #+#             */
/*   Updated: 2023/01/28 17:25:02 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nbr)
{
	int		i;

	i = 0;
	if (nbr == -2147483648)
	{
		i += write(1, "-2", 2);
		i += ft_putnbr(147483648);
	}
	else if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr *= -1;
		i += ft_putnbr(nbr);
	}
	else if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	else
		i += ft_putchar(nbr + '0');
	return (i);
}

int	list_arg(va_list arg, char w)
{
	int	i;

	i = 0;
	if (w == 'd' || w == 'i')
		i += ft_putnbr(va_arg(arg, int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		k;

	i = 0;
	k = 0;
	va_start (list, str);
	while (str[i] != 0)
	{
		if (str [i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			k += list_arg (list, str[i + 1]);
			i++;
		}
		else
		{
			k += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(list);
	return (k);
}
