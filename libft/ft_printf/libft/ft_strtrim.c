/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:42:58 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 21:51:37 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	trim_len;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_charset(s1[start], set) && start <= end)
		start++;
	while (is_charset(s1[end], set) && end > start)
		end--;
	trim_len = end - start + 1;
	dst = (char *)malloc((trim_len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s1[start], trim_len + 1);
	return (dst);
}

// int	main(void)
// {
// 	char	s1[] = " \t\n42Tokyo\v\f\r";
// 	char	s2[] = "";
// 	char	s3[] = " \t\n\v\f\r";
// 	char	set[] = " \t\n\v\f\r";
//
// 	printf("%s\n", ft_strtrim(s1, set));
// 	printf("%s\n", ft_strtrim(s2, set));
// 	printf("%s\n", ft_strtrim(s3, set));
// }
