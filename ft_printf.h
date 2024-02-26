/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:56:14 by rd-agost          #+#    #+#             */
/*   Updated: 2024/02/26 15:29:17 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long long n);
int		ft_format(va_list ap, char format);
int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned long n, int is_uppercs);
int		ft_putptr(unsigned long int memory_address);

#endif