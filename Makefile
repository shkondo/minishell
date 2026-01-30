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

# readline (brew version for rl_replace_line support)
READLINE_DIR = $(shell brew --prefix readline 2>/dev/null || echo /opt/homebrew/opt/readline)
INCLUDES = -I include -I libft -I $(READLINE_DIR)/include
READLINE_FLAGS = -L$(READLINE_DIR)/lib -lreadline

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
       src/expander/dequote.c \
       src/expander/expand_cmd.c \
       src/signals/sig.c \
       src/signals/sig_heredoc.c \
       src/builtins/builtins.c \
       src/builtins/echo.c \
       src/builtins/cd.c \
       src/builtins/pwd.c \
       src/builtins/export.c \
       src/builtins/unset.c \
       src/builtins/env.c \
       src/builtins/exit.c \
       src/redirection/redir.c \
       src/redirection/redir_utils.c \
       src/redirection/heredoc.c \
       src/executor/execute_cmd.c \
       src/executor/findcmd.c \
       src/pipeline/pipeline.c \
       src/pipeline/pipe_utils.c

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
