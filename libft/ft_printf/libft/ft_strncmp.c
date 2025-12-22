/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:18:05 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/05 10:21:08 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((t_uint8_t)s1[i] - (t_uint8_t)s2[i]);
}

// int	main(void)
// {
// 	const char	s1[] = "42tokyo";
// 	const char	s2[] = "42Tokyo";
// 	const char	s3[] = "32tokyo";
//
// 	printf("%d\n", ft_strncmp(s1, s2, 0));
// 	printf("%d\n", ft_strncmp(s1, s2, 5));
// 	printf("%d\n", ft_strncmp(s1, s3, 3));
// }
