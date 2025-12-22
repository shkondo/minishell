/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:54:34 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 22:10:25 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <sys/types.h>

void	ft_bzero(void *s, size_t n)
{
	t_uint8_t	*ptr;
	size_t		i;

	ptr = (t_uint8_t *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	return ;
}
