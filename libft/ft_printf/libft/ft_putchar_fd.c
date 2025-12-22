/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:44:55 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 21:17:28 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

// int	main(void)
// {
// 	size_t	i;
// 	char	s[] = "42tokyo";
//
// 	i = 0;
// 	while (s[i])
// 	{
// 		ft_putchar_fd(s[i], 1);
// 		i++;
// 	}
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }
