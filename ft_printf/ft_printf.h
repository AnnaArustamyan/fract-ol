/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:21:14 by aarustam          #+#    #+#             */
/*   Updated: 2024/04/08 17:33:48 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		print_char(char c);
int		print_str(char *str);
int		print_decim(int n);
void	ft_putnbr(int n);
int		ft_printf(const char *str, ...);
int		parz(char c, va_list args);
void	ft_putunbr(unsigned int n);
int		print_unsigned(unsigned int n);
void	ft_putchar(char c);
int		print_ptr(unsigned long long p);
void	print_ptr_hex(unsigned long long p, char *base);
int		print_lower_hex(unsigned int p);
int		print_upper_hex(unsigned int p);

#endif
