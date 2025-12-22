/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:51:42 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 22:10:25 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	t_uint8_t	uc;

	i = ft_strlen(s);
	uc = (t_uint8_t)c;
	while (i >= 0)
	{
		if (s[i] == uc)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
