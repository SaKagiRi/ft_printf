/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:59:33 by knakto            #+#    #+#             */
/*   Updated: 2024/09/07 04:01:47 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_print
{
	int		temp;
	int		len;
	va_list	arg;
}	t_print;

int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_printf(const char *str, ...);
int	ft_putnbr(int nbr, int len);
int	ft_percent(void);
int	ft_putunsignedint(unsigned int nbr, int len);
int	ft_hex(unsigned int dec, int len, int sw);
int	ft_putptr(unsigned long ptr);

#endif
