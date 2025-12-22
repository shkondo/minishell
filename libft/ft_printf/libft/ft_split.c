/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:46:37 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 21:17:42 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!(*s == c))
		{
			count++;
			while (*s && !(*s == c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

int	free_all(char **arr, size_t i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (0);
}

int	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (!ft_strchr(s, c))
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	**arr;

	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = word_len(s, c);
			arr[i] = ft_substr(s, 0, len);
			if (!arr[i])
				return (free_all(arr, i), NULL);
			s += len;
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

// int	main(void)
// {
//   char	s[] = "Gaspard de la Nuit";
//   char	c;
//   char	**result;
//   size_t	i;
//
//   c = ' ';
//   i = 0;
//   result = ft_split(s, c);
//   while (result[i])
//   {
//     printf("%s\n", result[i]);
//     i++;
//   }
//   i = 0;
//   while(result[i])
//   {
//     free(result[i]);
//     i++;
//   }
//   free(result);
//   return (0);
// }
