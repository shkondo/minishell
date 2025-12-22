/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 06:19:17 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/11 12:21:20 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits_long(unsigned long n, size_t base_len)
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

static char	*ft_ultoa(unsigned long n)
{
	char	*hex_chars;
	size_t	digits;
	char	*res_arr;
	size_t	i;

	hex_chars = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits_long(n, 0x10);
	res_arr = (char *)malloc((digits + 1) * sizeof(char));
	if (!res_arr)
		return (NULL);
	res_arr[digits] = '\0';
	i = digits;
	while (n != 0)
	{
		i--;
		res_arr[i] = hex_chars[n % 0x10];
		n /= 0x10;
	}
	return (res_arr);
}

char	*print_pointer(void *addr)
{
	char	*hex_addr;
	char	*res_arr;

	if (addr == NULL)
		return (ft_strdup("(nil)"));
	hex_addr = ft_ultoa((unsigned long)addr);
	if (!hex_addr)
		return (NULL);
	res_arr = ft_strjoin("0x", hex_addr);
	free(hex_addr);
	if (!res_arr)
		return (NULL);
	return (res_arr);
}
