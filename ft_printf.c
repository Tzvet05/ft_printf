/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:31:49 by ttrave            #+#    #+#             */
/*   Updated: 2023/12/14 18:13:30 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_conversion(va_list arg, t_params params)
{
	char	spec;

	spec = params.spec;
	if (!ft_in(spec, "cspdiuxX%"))
		return (ft_print_format(params));
	if (spec == 'c')
		return (ft_conv_char(params, (char)va_arg(arg, int)));
	else if (spec == 's')
		return (ft_conv_str(params, va_arg(arg, char *)));
	else if (spec == 'p')
		return (ft_conv_ptr(params, va_arg(arg, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_conv_int(params, va_arg(arg, int)));
	else if (spec == 'u')
		return (ft_conv_uint(params, va_arg(arg, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_conv_hex(params, va_arg(arg, unsigned int)));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (ft_print_format(params));
}

long	ft_parse(const char *s, va_list arg)
{
	size_t		i;
	long		converted;
	short		error;
	size_t		wrote;
	t_params	params;

	i = 0;
	error = 0;
	wrote = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i += ft_get_params(&s[i], arg, &params, &error);
			if (error == 2)
				return (-1);
			converted = ft_conversion(arg, params);
		}
		else
			converted = ft_print_identical(&s[i], &i);
		if (converted == -1)
			return (-1);
		wrote += converted;
	}
	return (wrote);
}

int	ft_printf(const char *format, ...)
{
	long		wrote;
	va_list		arg;

	wrote = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	wrote = ft_parse(format, arg);
	va_end(arg);
	if (wrote == -1 || wrote > INT_MAX)
		return (-1);
	return (wrote);
}
