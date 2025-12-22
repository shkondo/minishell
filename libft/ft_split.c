/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:46:37 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/09 01:07:05 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
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

static void	*free_all(char **arr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	return (NULL);
}

static size_t	word_len(char const *s, char c)
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

	if (!s)
		return (NULL);
	arr = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!arr)
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
				return (free_all(arr, i));
			s += len;
			i++;
		}
	}
	return (arr);
}

// #include <stdio.h>
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
