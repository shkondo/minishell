/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:17:23 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 21:15:55 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t	get_digits(int n)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		digits++;
	}
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*zero_or_min(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	digits;
	char	*dst;

	digits = get_digits(n);
	if (n == 0 || n == -2147483648)
		return (zero_or_min(n));
	dst = (char *)malloc((digits + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst[digits] = '\0';
	if (n < 0)
	{
		n = -n;
		dst[0] = '-';
	}
	i = digits - 1;
	while (n > 0)
	{
		dst[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (dst);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }
