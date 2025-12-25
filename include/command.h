/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:29:53 by shkondo           #+#    #+#             */
/*   Updated: 2025/12/25 18:43:38 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define TK_WORD 0
# define TK_PIPE 1
# define TK_REDIR_IN 2
# define TK_REDIER_OUT 3
# define TK_HEREDOC 4
# define TK_APPEND 5

# define W_HASDOLLAR 0X01
# define W_QUOTED 0x02
# define W_SINGLEQUOTE 0x04
# define W_DOUBLEQUOTE 0x08
# define W_EXPANDED 0x10

# define ERR_SYNTAX 2
# define ERR_PERM 126
# define ERR_CMD 127

typedef enum e_tok_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND
}					t_tok_type;

typedef struct s_word
{
	char			*str;
	int				type;
	int				flags;
}					t_word;

typedef struct s_token
{
	t_word			*word;
	struct s_token	*next;
}					t_token;

t_word				*create_word(char *str, int type);
t_word				*copy_word(t_word *word);
void				free_word(t_word *word);
void				set_word_flags(t_word *word, char *str);

t_token				*create_token(t_word *word, t_token *next);
t_token				*token_add_back(t_token **lst, t_word *word);
t_token				*copy_tokens(t_token *tokens);
void				free_tokens(t_token *tokens);
size_t				token_list_size(t_token *token);

t_token				*tokenize(char *line);

#endif
