/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:07:12 by knakto            #+#    #+#             */
/*   Updated: 2024/09/07 04:01:12 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_hex(unsigned long dec, int len)
{
	unsigned long	nb;
	char			*d;

	d = "0123456789abcdef";
	if (dec >= 16)
		len += ft_ptr_hex(dec / 16, len);
	nb = dec % 16;
	if (write(1, &d[nb], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	if (ptr == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = 2;
	if (ptr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		len++;
	}
	else
		len += ft_ptr_hex(ptr, 0);
	return (len);
}
