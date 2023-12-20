/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:07:23 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/30 19:07:27 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_parse_flags(const char *s, t_params *params)
{
	size_t		i;
	t_params	*ptr;

	i = 0;
	ptr = params;
	while (ft_in(s[i], "-0 +#"))
	{
		if (s[i] == '-')
			ptr->pad_right = 1;
		if (s[i] == '0')
			ptr->pad_char = '0';
		if (s[i] == ' ' && ptr->sign != '+')
			ptr->sign = ' ';
		if (s[i] == '+')
			ptr->sign = '+';
		if (s[i] == '#')
			ptr->base = 1;
		i++;
	}
	if (ptr->pad_right)
		ptr->pad_char = ' ';
	return (i);
}

size_t	ft_parse_width(const char *s, va_list arg, t_params *params,
short *error)
{
	size_t	i;
	long	n;

	if (s[0] == '*')
	{
		n = (long)va_arg(arg, int);
		if (n < 0)
		{
			n *= -1;
			params->pad_right = 1;
			params->pad_char = ' ';
		}
		params->width = (size_t)n;
		return (1);
	}
	i = 0;
	n = 0;
	while (ft_isdigit(s[i]))
		n = (10 * n) + (s[i++] - 48);
	if (n > 2147483647 && !(*error))
		*error = 2;
	else if (i)
		params->width = (int)n;
	return (i);
}

size_t	ft_parse_prec(const char *s, va_list arg, t_params *params,
short *error)
{
	size_t	i;
	size_t	n;

	if (s[0] != '.')
		return (0);
	if (s[1] == '*')
	{
		params->precision = va_arg(arg, int);
		return (2);
	}
	i = 1;
	n = 0;
	while (ft_isdigit(s[i]))
	{
		n = (10 * n) + (s[i] - 48);
		i++;
	}
	if (n > 2147483647 && !(*error))
		*error = 2;
	else
		params->precision = (int)n;
	return (i);
}

size_t	ft_parse_specifier(const char c, t_params *params, short *error)
{
	if (!c)
	{
		if ((!*error))
			*error = 2;
		return (0);
	}
	if (ft_in(c, "cspdiuxX%"))
	{
		params->spec = c;
		return (1);
	}
	params->spec = c;
	*error = 1;
	return (1);
}
