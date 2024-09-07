/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heximal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 01:12:38 by knakto            #+#    #+#             */
/*   Updated: 2024/09/07 04:00:32 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int dec, int len, int sw)
{
	unsigned int	nb;
	char			*d;

	d = "0123456789ABCDEF";
	if (sw == 1)
		d = "0123456789abcdef";
	if (dec >= 16)
		len += ft_hex(dec / 16, len, sw);
	nb = dec % 16;
	if (write(1, &d[nb], 1) == -1)
		return (-1);
	len++;
	return (len);
}
