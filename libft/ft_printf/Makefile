# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 12:08:01 by shkondo           #+#    #+#              #
#    Updated: 2025/05/11 12:08:02 by shkondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS_DIR = srcs

SRC_FILES_NAMES = ft_printf \
                  ft_printf_chars \
                  ft_printf_decimals \
                  ft_printf_hexs \
                  utils_printf_hex \
                  utils_printf_pointer

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(SRC_FILES_NAMES)))

OBJS = $(addsuffix .o, $(SRC_FILES_NAMES))

INCLUDES = -I$(SRCS_DIR) -I$(LIBFT_DIR)

.PHONY: all clean fclean re libft

all: $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: $(SRCS_DIR)/%.c $(SRCS_DIR)/ft_printf.h $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

libft:
	@$(MAKE) -C $(LIBFT_DIR)
