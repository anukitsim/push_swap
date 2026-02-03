/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsimint <atsimint@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:57:14 by atsimint          #+#    #+#             */
/*   Updated: 2025/10/22 17:40:14 by atsimint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(va_list *args, char conversion_char)
{
	if (conversion_char == 'c')
	{
		return (ft_print_char(args));
	}
	else if (conversion_char == 's')
	{
		return (ft_print_string(args));
	}
	else if (conversion_char == 'd' || conversion_char == 'i')
	{
		return (ft_print_int(args));
	}
	return (0);
}
