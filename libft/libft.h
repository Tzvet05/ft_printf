/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:52:35 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/01 12:12:29 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_isdigit(char c);
void	*ft_memset(void *s, int c, size_t n);
short	ft_in(char c, char *s);
size_t	ft_strlen(char *s);
void	ft_strncpy(char *dst, char *src, size_t n);

#endif
