/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsimint <atsimint@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:57:53 by atsimint          #+#    #+#             */
/*   Updated: 2025/10/22 17:38:39 by atsimint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(va_list args);
int	ft_print_string(va_list args);
int	ft_print_int(va_list args);
int	ft_putnbr(long n);
int	ft_handle_format(va_list args, char conversion_char);

#endif
