/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:35:33 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/28 17:49:37 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define INT_MAX 2147483647

typedef struct s_params
{
	short	pad_right;
	char	pad_char;
	char	sign;
	short	base;
	size_t	width;
	int		precision;
	char	spec;
}	t_params;

int		ft_printf(const char *s, ...);
long	ft_conversion(va_list arg, t_params params);
long	ft_parse(const char *s, va_list arg);

long	ft_conv_char(t_params params, char c);
long	ft_conv_str(t_params params, char *str);
long	ft_conv_ptr(t_params params, void *ptr);
long	ft_conv_int(t_params params, int nbr);
long	ft_conv_uint(t_params params, unsigned int nbr);

long	ft_conv_hex(t_params params, size_t nbr);
void	ft_putbase(char *buffer, t_params params, size_t nbr, size_t i_nbr);
char	*ft_alloc_hex(t_params *params, size_t *size, size_t *len, size_t nbr);
long	ft_conv_null_str(t_params params);

size_t	ft_parse_flags(const char *s, t_params *params);
size_t	ft_parse_width(const char *s, va_list arg, t_params *params,
			short *error);
size_t	ft_parse_prec(const char *s, va_list arg, t_params *params,
			short *error);
size_t	ft_parse_specifier(const char c, t_params *params, short *error);

void	ft_init_params(t_params *params);
size_t	ft_get_params(const char *s, va_list arg, t_params *params,
			short *error);

long	ft_print_identical(const char *format, size_t *index);
long	ft_print_format(t_params params);
void	ft_format_width_prec(char *buffer, size_t *i, t_params params);
void	ft_format_flags(char *to_print, size_t *i, t_params params);
size_t	ft_format_len(t_params params);

size_t	ft_strlen(char *str);
size_t	ft_in(char c, char *s);
size_t	ft_isdigit(char c);
void	ft_memset(void *s, int c, size_t n);
void	ft_strncpy(char *dst, char *src, size_t n);

size_t	ft_len_nbr(long int nbr);
size_t	ft_len_unbr(size_t n, size_t radix);
void	ft_puthex(char *str, size_t len, size_t nbr, char spec);
void	ft_putnbr(char *str, size_t len, char sign, long nbr);
size_t	ft_max(size_t n1, size_t n2);

#endif
