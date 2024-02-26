/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:23:55 by rd-agost          #+#    #+#             */
/*   Updated: 2024/02/26 15:05:20 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long n)
{
	long	nb;
	int		c;

	nb = n;
	c = 0;
	if (nb == -2147483648)
	{
		c += write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		c += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		c += ft_putnbr(nb / 10);
		c += ft_putchar((nb % 10) + '0');
	}
	else
		c += ft_putchar(nb + '0');
	return (c);
}

int	ft_puthex(unsigned long n, int is_uppercs)
{
	char	*lowcase;
	char	*upcase;
	int		len;
	int		temp;

	lowcase = "0123456789abcdef";
	upcase = "0123456789ABCDEF";
	len = 0;
	if (n == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	if (n > 0)
	{
		temp = n % 16;
		if ((n / 16) > 0)
			len += ft_puthex((n /= 16), is_uppercs);
		if (is_uppercs == 0)
			len += ft_putchar(lowcase[temp]);
		else if (is_uppercs == 1)
			len += ft_putchar(upcase[temp]);
	}
	return (len);
}

int	ft_putptr(unsigned long memory_address)
{
	unsigned long long	temp;
	int					len;

	len = 0;
	if (!memory_address)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	temp = (unsigned long long)memory_address;
	len += write(1, "0x", 2);
	len += ft_puthex(temp, 0);
	return (len);
}
