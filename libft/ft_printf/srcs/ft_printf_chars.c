/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:19:20 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/11 07:12:28 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_char(char c)
{
	write(STDOUT_FILENO, &c, sizeof(c));
	return (1);
}

static int	handle_string(char *s)
{
	int	len;

	if (!s)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}

static int	handle_percent(void)
{
	write(STDOUT_FILENO, "%", sizeof(char));
	return (1);
}

int	process_chars(const char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(va_arg(args, int)));
	else if (specifier == 's')
		return (handle_string(va_arg(args, char *)));
	else if (specifier == '%')
		return (handle_percent());
	return (-1);
}
