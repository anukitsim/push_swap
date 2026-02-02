/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsimint <atsimint@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:56:46 by atsimint          #+#    #+#             */
/*   Updated: 2025/10/22 13:27:25 by atsimint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += write(1, &(format[i]), 1);
			else
				count += ft_handle_format(args, format[i]);
		}
		else
		{
			count += write(1, &(format[i]), 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
