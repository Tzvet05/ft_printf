/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:38:39 by ttrave            #+#    #+#             */
/*   Updated: 2023/12/14 18:38:55 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_conv_char(t_params params, char c)
{
	char	*buffer;
	size_t	size;
	long	wrote;

	size = ft_max(params.width, 1);
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	if (params.width > 1)
		ft_memset(buffer, ' ', size);
	if (params.pad_right)
		buffer[0] = c;
	else
		buffer[size - 1] = c;
	wrote = write(1, buffer, size);
	free(buffer);
	return (wrote);
}

long	ft_conv_str(t_params params, char *str)
{
	char	*buffer;
	size_t	size;
	size_t	len;
	long	wrote;

	if (!str)
		return (ft_conv_null_str(params));
	len = ft_strlen(str);
	if (params.precision >= 0 && (size_t)params.precision < len)
		len = params.precision;
	size = ft_max(len, params.width);
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	if (params.width > len)
		ft_memset(buffer, ' ', size);
	if (params.pad_right)
		ft_strncpy(buffer, str, len);
	else
		ft_strncpy(&buffer[size - len], str, len);
	wrote = write(1, buffer, size);
	free(buffer);
	return (wrote);
}

long	ft_conv_ptr(t_params params, void *ptr)
{
	if (!ptr)
	{
		params.precision = -1;
		return (ft_conv_str(params, "(nil)"));
	}
	params.base = 1;
	return (ft_conv_hex(params, (size_t)ptr));
}

long	ft_conv_int(t_params params, int nbr)
{
	char	*buffer;
	long	wrote;
	size_t	size;
	size_t	len;

	if (!nbr && !params.precision && !params.width)
		return (0);
	if (params.pad_char == '0' && params.width > 0)
		params.precision = params.width - (params.sign != 0 || nbr < 0);
	len = ft_len_nbr(nbr);
	if (params.precision >= 0 && (size_t)params.precision > len)
		len = params.precision;
	len += (params.sign != 0 || nbr < 0);
	size = ft_max(params.width, len);
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	ft_memset(buffer, params.pad_char, size);
	if (params.pad_right && !(!nbr && !params.precision))
		ft_putnbr(buffer, len, params.sign, nbr);
	else if (!(!nbr && !params.precision))
		ft_putnbr(&buffer[size - len], len, params.sign, nbr);
	wrote = write(1, buffer, size);
	free(buffer);
	return (wrote);
}

long	ft_conv_uint(t_params params, unsigned int nbr)
{
	char	*buffer;
	long	wrote;
	size_t	size;
	size_t	len;

	if (!nbr && !params.precision && !params.width)
		return (0);
	if (params.pad_char == '0' && params.width > 0)
		params.precision = params.width;
	len = ft_len_nbr(nbr);
	if (params.precision >= 0 && (size_t)params.precision > len)
		len = params.precision;
	size = ft_max(params.width, len);
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	ft_memset(buffer, params.pad_char, size);
	if (params.pad_right && !(!nbr && !params.precision))
		ft_putnbr(buffer, len, params.sign, nbr);
	else if (!(!nbr && !params.precision))
		ft_putnbr(&buffer[size - len], len, params.sign, nbr);
	wrote = write(1, buffer, size);
	free(buffer);
	return (wrote);
}
