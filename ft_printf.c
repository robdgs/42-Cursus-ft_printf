/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:00 by rd-agost          #+#    #+#             */
/*   Updated: 2024/02/26 15:22:26 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(ap, char *));
	else if (format == '%')
		char_printed += ft_putchar('%');
	else if (format == 'd' || format == 'i')
		char_printed += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		char_printed += ft_putnbr(va_arg(ap, unsigned int));
	else if (format == 'x')
		char_printed += ft_puthex((long)va_arg(ap, unsigned int), 0);
	else if (format == 'X')
		char_printed += ft_puthex((long)va_arg(ap, unsigned int), 1);
	else if (format == 'p')
		char_printed += (long)ft_putptr(va_arg(ap, unsigned long));
	return (char_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_format(ap, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (char_printed);
}

/* int	main(void)
{
	char	uno = 'a';
 	char	prova2[] = "mamma funzionaaaa";
 	int		prova_3 = -2147483648;
 	long	prova_4 = 2147483649;
	char	*str = NULL;
	
	ft_printf("%%c __________________________\n");
	ft_printf("ft prima prova di char: %c\n", uno);
	printf("prima prova di char: %c\n", uno);
	printf("n char %d\n", ft_printf("prima prova di char: %c\n", uno));
	ft_printf("%%s __________________________\n");
	ft_printf("seconda prova stringa mia : %s\n", prova2);
	printf("seconda prova stringa real : %s\n", prova2);
	ft_printf("%%%% __________________________\n");
	ft_printf("proviamo la doppia percentuale mia : %%\n");
	printf("doppia percentuale real : %%\n");
	ft_printf("%%d %%i __________________________\n");
	ft_printf("prova numero mia: %d %i\n", prova_3, prova_3);
	printf("n char mio %d\n", ft_printf("prova n: %d %i \n", prova_3, prova_3));
	printf("n char real %d\n", printf("prova n: %d %i \n", prova_3, prova_3));
	ft_printf("%%u __________________________\n");
	ft_printf("prova unsigned mio: %u\n", prova_4);
	printf("prova unsigned real: %u\n", prova_4);
 	ft_printf("%%x __________________________\n");
 	printf("esad reale: %x\n", 'c');
 	ft_printf("esad mio: %x\n", 'c');
 	printf("esad reale: %x\n", -2147483647);
 	ft_printf("esad mio: %x\n", -2147483647);
 	printf("esad reale: %x\n", 2147483647);
 	ft_printf("esad mio:%x\n", 2147483647);
 	ft_printf("%%X _________________________\n");
 	printf("esad vero: %X\n", 2147483647);
 	ft_printf("esad mio: %X\n", 2147483647);
 	printf("esad vero: %X\n", -2147483647);
 	ft_printf("esad mio: %X\n", -2147483647);
	ft_printf("%%p _________________________\n");
	printf("Real: %p\n", &uno);
	ft_printf("Mine: %p\n", &uno);
	printf("Real: %p\n", &prova_4);
	ft_printf("Mine: %p\n", &prova_4);
	printf("Real: %p\n", str);
	ft_printf("Mine: %p\n", str);
 } */