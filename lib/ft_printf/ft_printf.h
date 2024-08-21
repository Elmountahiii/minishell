/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:23:13 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/20 12:27:17 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../lib.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		put_str(char *str);
int		print_address(void *adr);
int		put_char(char c);
int		put_hex(unsigned long nbr, char format);
int		put_nbr(int nbr);
int		put_nbr_u(unsigned int nbr);
int		handle_formats(const char *format, va_list args, int *i);
int		is_format(char format);
int		is_bouns(char c);
int		is_number(char c);
int		handle_bonus(int *i, const char *format, va_list args);
int		ft_atoiv1(const char *str, int *i);
int		number_len(int number);
int		handle_x(char sign, int width, char format, unsigned long nbr);
int		handle_d_i(char sign, int nbr, int len, int *c);
int		handle_s(int nbr, char *str, int *c);
int		hex_len(unsigned long number);
void	get_sign(int *i, const char *format, int *len, char *sign);
int		handle_p(int len, void *adr, int *i);
int		handle_c(int len, char c, int *i);

#endif