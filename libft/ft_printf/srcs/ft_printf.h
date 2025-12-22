/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:08:31 by shkondo           #+#    #+#             */
/*   Updated: 2025/05/10 09:45:20 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		process_chars(const char specifier, va_list args);
int		process_decimals(const char specifier, va_list args);
int		process_hexs(const char specifier, va_list args);

size_t	count_digits(unsigned int n, size_t base_len);
char	*print_hex_lower(unsigned int n);
char	*print_hex_upper(unsigned int n);
char	*print_pointer(void *addr);

#endif
