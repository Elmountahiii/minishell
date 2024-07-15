/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/15 16:01:48 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "./lib/lib.h"

typedef enum {
	WORD,
	SPACE,
	PIPE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	REDIRECTION_IN,
	REDIRECTION_OUT,
	APPEND,
	HEREDOC,
	ENV,
} t_token_type;

typedef enum {
	NORMAL,
	IN_SINGLE_QUOTE,
	IN_DOUBLE_QUOTE,
} t_word_type;

typedef struct s_token {
	t_token_type	token_type;
	t_word_type		word_type;
	char			*value;
} t_token;

typedef  struct e_tokens_list {
	t_token				*token;
	struct e_tokens_list	*next;
} t_tokens_list;


int		ft_sub_alloc(char *str);
int		ft_shift_quotes(char *str);
char	*ft_substr_v2(char *str, int i);
int		ft_is_special_char(char c);
// lexer
char	**ft_lexical_spliter(char *str);
int		ft_skip(char *str);
int		ft_is_special_char(char c);
int		ft_skip_special(char *str);
int		ft_check_space(char c);
int		ft_count_lexer_tokens(char *str);
int		ft_count_skip(char *str);
char	*ft_lexer_substr(char *line);
char	**ft_extract(char *line);
t_tokens_list	*ft_init_token_list(char *line);
void	ft_print_tokens_info(t_tokens_list *head);
#endif 