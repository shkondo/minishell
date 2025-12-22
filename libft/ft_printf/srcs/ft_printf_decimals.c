/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 02:54:28 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/11 07:12:35 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa(unsigned int n)
{
	size_t	i;
	size_t	digits;
	char	*res_arr;

	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 10);
	res_arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!res_arr)
		return (NULL);
	res_arr[digits] = '\0';
	i = digits - 1;
	while (n != 0)
	{
		res_arr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res_arr);
}

static int	handle_int(int n)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

static int	handle_uint(unsigned int n)
{
	char	*s;
	int		len;

	s = ft_uitoa(n);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	process_decimals(const char specifier, va_list args)
{
	if (specifier == 'i' || specifier == 'd')
		return (handle_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (handle_uint(va_arg(args, unsigned int)));
	return (-1);
}
