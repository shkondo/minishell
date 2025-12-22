/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:44:25 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 21:18:39 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cpy_len;
	char	*dst;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dst = (char *)malloc(1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (ft_strlen(s) - start < len)
		cpy_len = ft_strlen(s) - start;
	else
		cpy_len = len;
	dst = (char *)malloc((cpy_len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, cpy_len + 1);
	return (dst);
}

// int	main(void)
// {
// 	char	s[] = "Hello, 42Tokyo";

// 	printf("%d\n", ft_substr(s, 6, 10));
// 	return (0);
// }
//
