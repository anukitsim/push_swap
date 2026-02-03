/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsimint <atsimint@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:24:23 by atsimint          #+#    #+#             */
/*   Updated: 2025/10/22 17:33:17 by atsimint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *args)
{
	int		count;
	long	int_arg;

	count = 0;
	int_arg = va_arg(*args, int);
	if (int_arg < 0)
	{
		count += write(1, "-", 1);
		int_arg = -int_arg;
	}
	count += ft_putnbr(int_arg);
	return (count);
}
