/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:44:51 by ttrave            #+#    #+#             */
/*   Updated: 2023/12/17 13:07:58 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long	ft_conv_hex(t_params params, size_t nbr)
{
	char	*buffer;
	long	wrote;
	size_t	size;
	size_t	len;

	if (!nbr && !params.precision && !params.width)
		return (0);
	if (params.pad_char == '0' && params.width > 0)
		params.precision = params.width - 2;
	buffer = ft_alloc_hex(&params, &size, &len, nbr);
	if (!buffer)
		return (-1);
	ft_memset(buffer, params.pad_char, size);
	ft_putbase(buffer, params, nbr, size - len);
	if (params.pad_right && !(!nbr && !params.precision))
		ft_puthex(&buffer[2 * params.base], len, nbr, params.spec);
	else if (!(!nbr && !params.precision))
		ft_puthex(&buffer[size - len], len, nbr, params.spec);
	wrote = write(1, buffer, size);
	free(buffer);
	return (wrote);
}

void	ft_putbase(char *buffer, t_params params, size_t nbr, size_t i_nbr)
{
	char	*base;

	base = "0x";
	if (params.spec == 'X')
		base = "0X";
	if (nbr && (params.spec == 'p' || params.base) && params.pad_right)
		ft_strncpy(buffer, base, 2);
	else if (nbr && (params.spec == 'p' || params.base))
		ft_strncpy(&buffer[i_nbr - 2], base, 2);
}

char	*ft_alloc_hex(t_params *params, size_t *size, size_t *len, size_t nbr)
{
	char	*buffer;
	size_t	base;

	*len = ft_len_unbr(nbr, 16);
	if (params->precision >= 0 && (size_t)params->precision > *len)
		*len = params->precision;
	base = 0;
	if (params->base && nbr)
		base = 2;
	*size = ft_max(params->width, *len + base);
	buffer = malloc(*size * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

long	ft_conv_null_str(t_params params)
{
	char	*buffer;
	size_t	size;
	long	wrote;

	size = params.width;
	if (params.precision < 0 || params.precision > 5)
		size = ft_max(size, 6);
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	ft_memset(buffer, ' ', size);
	if (params.pad_right && (params.precision < 0 || params.precision > 5))
		ft_strncpy(buffer, "(null)", 6);
	else if (params.precision < 0 || params.precision > 5)
		ft_strncpy(&buffer[size - 6], "(null)", 6);
	wrote = write(1, buffer, size);
	free(buffer);
	return (wrote);
}
