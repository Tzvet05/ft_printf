/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:06:02 by ttrave            #+#    #+#             */
/*   Updated: 2023/12/13 19:08:46 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_len_nbr(long int nbr)
{
	size_t	len;

	len = !nbr;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

size_t	ft_len_unbr(size_t nbr, size_t radix)
{
	size_t	len;

	len = !nbr;
	while (nbr)
	{
		nbr /= radix;
		len++;
	}
	return (len);
}

void	ft_puthex(char *str, size_t len, size_t nbr, char spec)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (spec == 'X')
		hex = "0123456789ABCDEF";
	len--;
	while (len > 0)
	{
		str[len] = hex[nbr % 16];
		nbr /= 16;
		len--;
	}
	str[len] = hex[nbr % 16];
}

void	ft_putnbr(char *str, size_t len, char sign, long nbr)
{
	size_t	n;

	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	len--;
	while (len)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	str[len] = (n % 10) + 48;
	if (nbr < 0)
		str[0] = '-';
	else if (sign)
		str[0] = sign;
}

size_t	ft_max(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
