/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:25:09 by ttrave            #+#    #+#             */
/*   Updated: 2023/12/10 20:25:11 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_print_identical(const char *format, size_t *index)
{
	char	*buffer;
	long	wrote;
	size_t	size;
	size_t	i;

	size = 0;
	while (format[size] && format[size] != '%')
		size++;
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	i = 0;
	while (i < size)
	{
		buffer[i] = format[i];
		i++;
	}
	wrote = write(1, buffer, size);
	free(buffer);
	*index += size;
	return (wrote);
}

long	ft_print_format(t_params params)
{
	char	*buffer;
	long	size;
	size_t	i;

	size = ft_format_len(params);
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	i = 1;
	buffer[0] = '%';
	ft_format_flags(buffer, &i, params);
	ft_format_width_prec(buffer, &i, params);
	buffer[i] = params.spec;
	size = write(1, buffer, size);
	free(buffer);
	return (size);
}

void	ft_format_width_prec(char *buffer, size_t *i, t_params params)
{
	if (params.width > 0)
	{
		ft_putnbr(&buffer[*i], ft_len_unbr(params.width, 10), 0, params.width);
		*i += ft_len_unbr(params.width, 10);
	}
	if (params.precision >= 0)
	{
		buffer[*i] = '.';
		(*i)++;
		ft_putnbr(&buffer[*i],
			ft_len_unbr(params.precision, 10), 0, params.precision);
		*i += ft_len_unbr(params.precision, 10);
	}
}

void	ft_format_flags(char *buffer, size_t *i, t_params params)
{
	if (params.base)
	{
		buffer[*i] = '#';
		(*i)++;
	}
	if (params.sign)
	{
		buffer[*i] = params.sign;
		(*i)++;
	}
	if (params.pad_right)
	{
		buffer[*i] = '-';
		(*i)++;
	}
	if (params.pad_char == '0')
	{
		buffer[*i] = '0';
		(*i)++;
	}
}

size_t	ft_format_len(t_params params)
{
	size_t	size;

	size = 2;
	if (params.base)
		size++;
	if (params.sign)
		size++;
	if (params.pad_right)
		size++;
	if (params.pad_char == '0')
		size++;
	if (params.width > 0)
		size += ft_len_unbr(params.width, 10);
	if (params.precision >= 0)
		size += ft_len_unbr(params.precision, 10) + 1;
	return (size);
}
