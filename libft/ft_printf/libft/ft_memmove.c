/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 08:32:09 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/06 01:36:19 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	t_uint8_t		*d;
	const t_uint8_t	*s;

	if (!dst && !src)
		return (NULL);
	d = (t_uint8_t *)dst;
	s = (const t_uint8_t *)src;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else if (d != s)
		ft_memcpy(dst, src, n);
	return (dst);
}
