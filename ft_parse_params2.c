/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_params2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:55:43 by ttrave            #+#    #+#             */
/*   Updated: 2023/12/10 18:55:52 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_params(t_params *params)
{
	t_params	*ptr;

	ptr = params;
	ptr->pad_right = 0;
	ptr->pad_char = ' ';
	ptr->sign = 0;
	ptr->base = 0;
	ptr->width = 0;
	ptr->precision = -1;
	ptr->spec = 0;
}

size_t	ft_get_params(const char *s, va_list arg, t_params *params,
short *error)
{
	size_t	i;

	i = 1;
	ft_init_params(params);
	i += ft_parse_flags(&s[i], params);
	i += ft_parse_width(&s[i], arg, params, error);
	i += ft_parse_prec(&s[i], arg, params, error);
	i += ft_parse_specifier(s[i], params, error);
	if (params->precision >= 0)
		params->pad_char = ' ';
	if (params->spec == 'u')
		params->sign = 0;
	return (i);
}
