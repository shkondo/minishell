/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:43:39 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 22:11:25 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_uint32_t	i;
	char		*dst;

	if (!s)
		return (NULL);
	dst = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// char	to_upper(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }
//
// char	show_index(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (ft_toupper(c));
// 	else
// 		return (ft_tolower(c));
// }
//
// int	main(void)
// {
// 	char	*original;
//
// 	original = "Hello, World!";
// 	char *result1, *result2;
// 	result1 = ft_strmapi(original, to_upper);
// 	printf("Original: %s\n", original);
// 	printf("Upper case: %s\n", result1);
// 	result2 = ft_strmapi(original, show_index);
// 	printf("Alternating case: %s\n", result2);
// 	free(result1);
// 	free(result2);
// 	return (0);
// }
