/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:04:01 by knakto            #+#    #+#             */
/*   Updated: 2024/09/07 04:00:59 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(const char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, const char *));
	else if (c == 'p')
		len += ft_putptr(va_arg(arg, unsigned long));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int), 0);
	else if (c == 'u')
		len += ft_putunsignedint(va_arg(arg, unsigned int), 0);
	else if (c == 'x')
		len += ft_hex(va_arg(arg, unsigned int), 0, 1);
	else if (c == 'X')
		len += ft_hex(va_arg(arg, unsigned int), 0, 0);
	else if (c == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	t_print	print;

	print.len = 0;
	print.temp = 0;
	if (str == NULL)
		return (-1);
	va_start(print.arg, str);
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str == '%')
			print.temp = ft_check(*++str, print.arg);
		else
			print.temp = ft_putchar(*str);
		if (print.len == -1)
			return (-1);
		print.len += print.temp;
		str++;
	}
	va_end(print.arg);
	return (print.len);
}
