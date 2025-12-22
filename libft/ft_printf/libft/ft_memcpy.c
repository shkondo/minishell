/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:22:51 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/06 01:58:20 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	t_uint8_t		*d;
	const t_uint8_t	*s;

	if (!dst && !src)
		return (NULL);
	d = (t_uint8_t *)dst;
	s = (const t_uint8_t *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	int		src_arr[] = {10, 20, 30, 40, 50};
// 	int		*dst_arr;
// 	size_t	n_bytes;
// 	void	*ret_ptr;
//
// 	printf("-- Test 1: int array --\n");
// 	n_bytes = sizeof(src_arr);
// 	dst_arr = (int *)malloc(n_bytes);
// 	if (!dst_arr)
// 	{
// 		printf("Failed to allocate memory.\n");
// 		return (1);
// 	}
// 	printf("memory allocated.\n");
// 	printf("Calling ft_memcpy to copy %zu bytes...\n", n_bytes);
// 	ret_ptr = ft_memcpy(dst_arr, src_arr, n_bytes);
// 	if (ret_ptr == dst_arr)
// 		printf("Return pointer check: OK(returned dst)\n");
// 	else
// 		printf("FAIL: Return pointer mismatch. Expected %p, Got %p\n",
// 			(void *)dst_arr, ret_ptr);
// 	if (memcmp(dst_arr, src_arr, n_bytes) == 0)
// 	{
// 		printf("Content verification: OK\n");
// 		printf("Copied content: ");
// 		for (size_t i = 0; i < sizeof(src_arr) / sizeof(int); i++)
// 			printf("%d ", dst_arr[i]);
// 		printf("\n");
// 	}
// 	else
// 		printf("FAIL: Content mismatch after copy.\n");
// 	free(dst_arr);
// 	printf("Destination memory is freed.\n");
// }
