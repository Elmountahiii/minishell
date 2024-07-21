/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/21 15:38:07 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/lib.h"

typedef enum {
	WORD,
	SPACE,
	PIPE,
	SINGLE_QUOTE_WORD,
	DOUBLE_QUOTE_WORD,
	REDIRECTION_IN,
	REDIRECTION_OUT,
	APPEND,
	HEREDOC,
	ENV,
} t_token_type;

typedef enum {  STDIN_IO, STDOUT_IO, FILE_IO, PIPE_IO } IOType;
//DEFAULT_IO
typedef  struct e_tokens_list {
	t_token_type	type;
	char			*value;
	struct e_tokens_list	*next;
} t_tokens_list;

typedef struct s_command {
	char	**command_args; 
	char 	*path;
	IOType	in_type;
	IOType	out_type;
	char	*in_file;
	char	*out_file;
	bool	is_append;
	bool	is_heredoc;
	struct s_command	*next;
} t_command;

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
t_command  *ft_split_to_command(t_tokens_list *tokens_list);
void	until_pipe(t_command *node,t_tokens_list *tokens);
char **ft_append_to_list(char **list,char *command);
void	ft_tokens_add_back(t_tokens_list **tokens, t_tokens_list *new);
void	ft_commands_add_back(t_command **commands, t_command *new);
t_tokens_list	*ft_tokens_new(t_token_type type, char *value);

typedef struct t_env_list
{
	char				*key;
	char				*value;
	struct t_env_list	*next;
}t_env_list;

// builtins funcs and structs
char		*our_pwd(char **env);
int			our_env(char    **envp);
int			our_cd(char *path);
void		our_echo(char *str);
int			ft_strlen(char *s);
void		add_back_for_env(t_env_list **list, char *str);
t_env_list	*get_env_list(char **env);
void		print_env_list(t_env_list* list);
void		our_export(char	*var,char *value, t_env_list	*env_list);
void		our_unset(char *var, t_env_list   **list);


// end of builtins

#endif
void	ft_print_command_info(t_command *command);