/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 06:27:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/11 07:12:05 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_digits(unsigned int n, size_t base_len)
{
	size_t	digits;

	if (base_len < 2)
		return (1);
	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits++;
		n /= base_len;
	}
	return (digits);
}

char	*print_hex_lower(unsigned int n)
{
	char	*hex_lower;
	size_t	i;
	size_t	digits;
	char	*res_arr;

	hex_lower = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 0x10);
	res_arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!res_arr)
		return (NULL);
	res_arr[digits] = '\0';
	i = digits;
	while (n != 0)
	{
		i--;
		res_arr[i] = hex_lower[n % 0x10];
		n /= 0x10;
	}
	return (res_arr);
}

char	*print_hex_upper(unsigned int n)
{
	char	*hex_upper;
	size_t	i;
	size_t	digits;
	char	*res_arr;

	hex_upper = "0123456789ABCDEF";
	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n, 0x10);
	res_arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!res_arr)
		return (NULL);
	res_arr[digits] = '\0';
	i = digits;
	while (n != 0)
	{
		i--;
		res_arr[i] = hex_upper[n % 0x10];
		n /= 0x10;
	}
	return (res_arr);
}
