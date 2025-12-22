/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:16:13 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/11 07:12:43 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_hex_lower(unsigned int n)
{
	char	*s;
	int		len;

	s = print_hex_lower(n);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

static int	handle_hex_upper(unsigned int n)
{
	char	*s;
	int		len;

	s = print_hex_upper(n);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

static int	handle_pointer(void *ptr)
{
	char	*s;
	int		len;

	s = print_pointer(ptr);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	process_hexs(const char specifier, va_list args)
{
	if (specifier == 'x')
		return (handle_hex_lower(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		return (handle_hex_upper(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else
		return (-1);
}
