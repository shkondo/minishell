/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:32:39 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/04 22:11:25 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	t_uint32_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

// void	to_upper(t_uint32_t i, char *c)
// {
// 	(void)i;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }
//
// int	main(void)
// {
// 	char	str[] = "42Tokyo";
//
// 	ft_striteri(str, to_upper);
// 	ft_putstr_fd(str, 1);
//   ft_putchar_fd('\n', 1);
// 	return (0);
// }
