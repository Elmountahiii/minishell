/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 16:27:48 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include "./lib/lib.h"
#include <sys/stat.h>

extern int exit_status;

typedef enum {
	WORD,
	SPACE_TOKEN,
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

typedef struct s_heredoc
{
	int				fd;
	char			*file_name;
	char			*dil;
	struct s_heredoc	*next;
}	t_heredoc;

typedef struct s_pipe
{
	int				fd[2];
	struct s_pipe	*next;
}	t_pipe;

t_pipe			*give_list_pipes(t_tokens_list	*tokens_list);
void			print_list_pipes(t_pipe	*pipes);

typedef struct t_env_list
{
	char				*key;
	char				*value;
	struct t_env_list	*next;
}t_env_list;

typedef struct t_list_files
{
	int					id;
	int					fd;
	char				*name;
	struct t_list_files	*next;
}t_list_files;

typedef struct s_command_files
{
	int					fd;
	t_token_type		type;
	char				*name;
	struct s_command_files	*next;
}t_command_files;

typedef struct s_command {
	char				**command_args;
	char 				*path;
	IOType				in_type;
	IOType				out_type;
	char				*in_file;
	char				*out_file;
	char				*dil;
	int					fd_in;
	int					fd_out;
	bool				is_append;
	bool				is_heredoc;
	int					index;
	t_command_files		*files_list;
	t_heredoc			*heredoc_list;
	struct s_command	*next;
} t_command;
typedef struct t_be_executed
{
	t_command		*commands_list;
	t_tokens_list	*tokens_list;
	t_pipe			*list_pipes;
	t_env_list		**env_list;
	int				list_size;
}t_be_executed;


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
void	until_pipe(t_command *node, t_tokens_list *tokens, t_command *head);
char **ft_append_to_list(char **list,char *command);
void	ft_tokens_add_back(t_tokens_list **tokens, t_tokens_list *new);
void	ft_commands_add_back(t_command **commands, t_command *new);
t_tokens_list	*ft_tokens_new(t_token_type type, char *value);
int		ft_check_syntax(t_tokens_list *list);
void	ft_skip_tokens_spaces(t_tokens_list **tokens);
char	*ft_clean_string(char **split);
int		ft_count_clean_string(char *str, t_token_type type, int len);
char	**ft_split_clean(char *str);
int		ft_count_split_clean(char *str);
char	*ft_join_until_space(char **tokens, int index);
int		ft_list_skip_spaces(char **tokens,int index);
int		ft_check_redout_syntax(t_tokens_list *list);
int		ft_check_redin_syntax(t_tokens_list *list);
int		ft_check_pipe_syntax(t_tokens_list *list);
int		syntax_error(char token);
int		ft_count_all_lines(char **split);
int		ft_skip_quotes(char *str, int i);
int		ft_is_valid_word(t_tokens_list *t);
char *ft_join(char *old, t_tokens_list **tokens);
void	ft_skip_tokens_spaces(t_tokens_list **tokens);
char	**ft_append_to_list_tokens(char **list, t_tokens_list **tokens);
char	**ft_append_to_list(char **list, char *command);
void	ft_handle_word(t_command *node, t_tokens_list **tokens);
t_command * ft_command_allocate();
int	ft_command_next(t_command **commands_list, t_tokens_list **tokens_list);
void	ft_skip_tokens_spaces(t_tokens_list **tokens);
char	**ft_append_to_list(char **list, char *command);
void	ft_handle_redirection(t_command *node, t_tokens_list **tokens);
int		ft_is_env(char *str);
void	ft_expend_tokens(t_tokens_list *commands, t_env_list *env);
char	*ft_get_key(char *str, int i);
char	*ft_append_char(char *str, char c);
char	*ft_get_key(char *str, int i);
char	*ft_expand(char *value, char **keys, t_env_list *env);
char	*ft_get_key_value(char *key, char **env);
int	ft_count_expand_alloc(char *str, t_env_list *env, char **keys);
int is_valid_expand(char c);
void close_pipes(t_pipe *list_pipes);
char *find_value(char * key ,t_env_list *env);
char	*ft_remove_quotes(char *str);

// heredoc
int			ft_heredoc_size(t_command *commands);
void		ft_heredoc_addback(t_heredoc **alst, t_heredoc *new);
t_heredoc	*ft_create_heredoc(t_command *list,char *dil, t_token_type type);
void		ft_init_heredoc(t_command *command);
void		ft_open_heredoc(t_heredoc *heredoc);
void		ft_fill_heredoc(t_command *command);

// cleaning functions
void	ft_clean(t_be_executed *to_execute);
void	ft_free_array(char **array);
void	ft_clean_files(t_command_files *list_of_files);
void	ft_clean_tokens(t_tokens_list *tokens_list);
void	ft_clean_commands(t_command *commands_list);
void	ft_clean_pipes(t_pipe *list_pipes);
void	ft_clean_heredoc(t_heredoc *list_heredoc);

// files 
t_command_files	*ft_create_file_node( char *file_name, t_token_type type);
int				ft_is_valid_file_name(t_token_type type);
t_heredoc		*ft_heredoc_last(t_heredoc *lst);
void			ft_files_addback(t_command_files **alst, t_command_files *new);
t_command_files	*ft_files_last(t_command_files *lst);
int				ft_is_valid_file_name(t_token_type type);
char			*ft_handle_file_name(t_tokens_list **tokens);
void			ft_select_files(t_command *command);
void			ft_open_files(t_command *command);
t_command_files *ft_correct_in_file(t_command_files *files_list);
t_command_files *ft_correct_out_file(t_command_files *files_list);

//  expanding
void	ft_tokens_expand(t_tokens_list *tokens_list, t_env_list *env_list);
int		ft_is_expandable(t_tokens_list *token);
int		ft_keys_count(char *str, t_token_type type);
char	**ft_split_keys(char *str , t_token_type type);
char	*ft_extract_key(char *str);
int		ft_is_env_char(char c);
char	*ft_link_key_value(char *str, char **keys ,t_env_list *env_list);
int		ft_count_for_dollar(char *str, int *index);
int		ft_count_at(char *str, int *index);
// builtins funcs and structs

void		our_pwd(t_command *command, t_be_executed	*to_execute, int procss);
void		our_env(t_command *command, t_be_executed	*to_execute, int procss);
void		our_echo(t_command *command, t_be_executed	*to_execute, int procss);
int			ft_strlen(char *s);
void		add_back_for_env(t_env_list **list, char *str);
t_env_list	*get_env_list(char **env);
void		print_env_list(t_env_list* list);
void		ft_export_env(t_env_list *env_list, int procss);
void		ft_export(t_command *command, t_be_executed	*to_execute, int procss);
void		ft_unset(t_command *command, t_be_executed	*to_execute, int procss);
void		our_cd(t_command *command, t_be_executed	*to_execute, int procss);
void		our_exit(t_command *command, t_be_executed	*to_execute, int procss);
char		**give_array_str(t_env_list *env_list);
void		close_other_pipes(t_command	*command, t_pipe *list_pipes);
void		add_to_env(char	*key, char	*value, t_env_list	**env_list);
int			check_every_arg(char *arg);
int			count_array_str(char **array);

// t_env_list	*get_env_list(char	**env)

// end of builtins


// function for list of files



int 			count_list(t_command *list);
void			print_list_files(t_list_files  *list_files);
t_list_files	*give_list_files(t_tokens_list	*list_tokens, t_command *list_commands);

// end of builtins

void			fill_command_paths(t_command *command_list, t_env_list *env);
t_be_executed	*give_executed(t_command *commands_list, t_pipe *list_pipes, t_tokens_list *tokens_list, t_env_list **env_list);


// execution
int				is_built_in(char	*command);
void			execute_things(t_be_executed *to_execute);
void			execute_command(t_command *command,	t_be_executed	*to_execute);
void			assign_output(t_command	*command, t_be_executed	*to_execute);
void			assign_input(t_command	*command, t_be_executed	*to_execute);
int				get_file_fd(t_command	*command, char i_o);
int				ft_is_executed(t_command *command);
int				ft_is_path(char *cmd);
void			ft_check_path_correct(char *cmd);

// end

void			ft_print_command_info(t_command *command);
#endif