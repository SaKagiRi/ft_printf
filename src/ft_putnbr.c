/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:48:51 by knakto            #+#    #+#             */
/*   Updated: 2024/09/07 04:00:12 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr, int len)
{
	int	nb;

	if (nbr == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (nbr < 0 && nbr != -2147483648)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nbr *= -1;
		len += 1;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10, 0);
	nb = nbr % 10 + '0';
	if (write(1, &nb, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putunsignedint(unsigned int nbr, int len)
{
	unsigned int	nb;

	if (nbr >= 10)
		len += ft_putunsignedint(nbr / 10, len);
	nb = nbr % 10 + '0';
	if (write(1, &nb, 1) == -1)
		return (-1);
	len++;
	return (len);
}
