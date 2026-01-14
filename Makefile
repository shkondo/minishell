# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2026/01/14 00:00:00 by shkondo           #+#    #+#             #
#    Updated: 2026/01/14 00:00:00 by shkondo          ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include -I libft

# readline
READLINE_FLAGS = -lreadline

# libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRCS = src/main.c \
       src/lexer/tokenizer.c \
       src/lexer/quote_utils.c \
       src/utils/lst_token.c \
       src/utils/lst_word.c \
       src/utils/general.c \
       src/parser/parser.c \
       src/parser/parse_command.c \
       src/parser/parse_redirect.c \
       src/parser/parser_utils.c \
       src/parser/make_cmd.c \
       src/parser/dispose_cmd.c \
       src/env/variables.c \
       src/env/variables_utils.c \
       src/env/init_env.c \
       src/expander/subst.c \
       src/expander/subst_expand.c \
       src/expander/param_expand.c \
       src/expander/dequote.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
