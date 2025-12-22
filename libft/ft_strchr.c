/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:04:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 22:10:25 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	t_uint8_t	uc;

	uc = (t_uint8_t)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "Hello, 42Tokyo!";
// 	const char	empty_str[] = "";
// 	char		*result;
//
// 	printf(" -- Test case --\n");
// 	result = ft_strchr(s, 'o');
// 	if (result != NULL)
// 		printf("Found: %p, \"%s\"\n", (void *)result, result);
// 	else
// 		printf("Found: (NULL)\n");
// 	printf("\n");
// 	result = ft_strchr(s, 'z');
// 	if (result != NULL)
// 		printf("Found: %p, \"%s\"\n", (void *)result, result);
// 	else
// 		printf("Found: (NULL) <- Expected\n");
// 	printf("\n");
// 	result = ft_strchr(s, '\0');
// 	if (result != NULL)
// 		printf("Found: %p, \"%s\" <- Expected\n", (void *)result, result);
// 	else
// 		printf("Found: (NULL)\n");
// 	printf("\n");
// 	result = ft_strchr(empty_str, 'A');
// 	if (result != NULL)
// 		printf("Found: %p, \"%s\"\n", (void *)result, result);
// 	else
// 		printf("Found: (NULL) <- Expected\n");
// 	printf("\n");
// 	result = ft_strchr(empty_str, '\0');
// 	if (result != NULL)
// 		printf("Found: %p, \"%s\" <- Expected\n", (void *)result, result);
// 	else
// 		printf("Found: (NULL)\n");
// 	printf("-- finished --\n");
// }
