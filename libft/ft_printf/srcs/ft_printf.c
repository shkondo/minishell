/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:49:32 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 09:45:22 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (process_chars(specifier, args));
	else if (specifier == 's')
		return (process_chars(specifier, args));
	else if (specifier == '%')
		return (process_chars(specifier, args));
	else if (specifier == 'i' || specifier == 'd')
		return (process_decimals(specifier, args));
	else if (specifier == 'u')
		return (process_decimals(specifier, args));
	else if (specifier == 'x' || specifier == 'X')
		return (process_hexs(specifier, args));
	else if (specifier == 'p')
		return (process_hexs(specifier, args));
	return (0);
}

static int	parse_and_print(const char *format, va_list args)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			count += handle_conversion(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = parse_and_print(format, args);
	va_end(args);
	return (count);
}
