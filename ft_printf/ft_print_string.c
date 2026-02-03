/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsimint <atsimint@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:56:19 by atsimint          #+#    #+#             */
/*   Updated: 2025/10/21 19:16:20 by atsimint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(va_list *args)
{
	char	*s;
	int		i;
	int		count;

	s = va_arg(*args, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		count += write(1, &(s[i]), 1);
		i++;
	}
	return (count);
}
