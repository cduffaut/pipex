/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:51:04 by csil              #+#    #+#             */
/*   Updated: 2023/10/13 17:51:50 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	print_c(char c);
int	print_s(char *s);
int	prct_case(const char *str, va_list stock, int i);
int	len_nbr(int nbr);
int	ft_putnbr(int n);
int	print_hexa(unsigned long nbr, int format);
int	unsigned_len(unsigned int nbr);
int	print_u(unsigned int n);
int	print_p(long long nbr);
int	print_hexa_p(unsigned long long nbr, int format);

#endif
