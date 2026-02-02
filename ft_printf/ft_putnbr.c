/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsimint <atsimint@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:28:27 by atsimint          #+#    #+#             */
/*   Updated: 2025/10/22 17:32:03 by atsimint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		count;
	char	digit_char;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	digit_char = (n % 10) + '0';
	count += write(1, &digit_char, 1);
	return (count);
}
