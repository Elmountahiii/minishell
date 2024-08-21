/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 18:43:15 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "./lib/lib.h"
# include <sys/stat.h>
# include <signal.h>

extern int	g_exit_status;

typedef enum s_token_type {
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
}	t_token_type;

typedef enum s_ttype {
	STDIN_IO,
	STDOUT_IO,
	FILE_IO,
	PIPE_IO 
}	t_ttype;

typedef struct e_tokens_list {
	t_token_type			type;
	char					*value;
	struct e_tokens_list	*next;
}	t_tokens_list;

typedef struct s_heredoc
{
	int					index;
	int					fd;
	char				*file_name;
	char				*dil;
	bool				expand_line;
	bool				done;
	struct s_heredoc	*next;
}	t_heredoc;

typedef struct s_pipe
{
	int				fd[2];
	struct s_pipe	*next;
}	t_pipe;

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
	int							index;
	char						*file_name;
	int							fd;
	t_token_type				type;
	char						**files;
	bool						is_ambiguous;
	char						*ambiguous_name;
	struct s_command_files		*next;
}t_command_files;

typedef struct s_command {
	char				**command_args;
	char				*path;
	bool				no_path;
	t_ttype				in_type;
	t_ttype				out_type;
	char				*in_file;
	char				*out_file;
	char				*dil;
	int					fd_in;
	int					fd_out;
	bool				is_append;
	bool				is_heredoc;
	bool				is_ambiguous;
	char				*ambiguous_name;
	int					index;
	t_command_files		*files_list;
	t_heredoc			*heredoc_list;
	struct s_command	*next;
}	t_command;

typedef struct t_be_executed
{
	t_command		*commands_list;
	t_tokens_list	*tokens_list;
	t_command_files	*files_list;
	t_heredoc		*heredoc_list;
	t_pipe			*list_pipes;
	t_env_list		**env_list;
	int				list_size;
}t_be_executed;

// pipes
t_pipe			*give_list_pipes(t_tokens_list	*tokens_list);
void			print_list_pipes(t_pipe	*pipes);
// spliting functions
int				ft_is_token(char *str);
t_token_type	ft_get_token_type(char *str);
int				ft_count_line_tokens(char *line);
int				ft_skip_quotess(char **line);
char			*ft_crate_quote(char **line);
int				ft_skip_spacee(char **line);
char			*ft_create_space(char **line);
int				ft_skip_word(char **line);
char			*ft_create_word(char **line);
int				ft_skip_env(char **line);
char			*ft_create_env(char **line);
char			*ft_create_redirection(char **line);
char			**ft_split_line(char *line);
void			ft_print_array(char **array);
// tokens functions
void			ft_tokens_addback(t_tokens_list **alst, t_tokens_list *new);
t_tokens_list	*ft_create_token(char *str);
t_tokens_list	*ft_add_tokens(char **tokens);
void			ft_print_tokens(t_tokens_list *tokens_list);
void			ft_token_skip(t_tokens_list **tokens, t_token_type type);
// syntax check functions
int				ft_check_redout_syntax(t_tokens_list *list);
int				ft_check_redin_syntax(t_tokens_list *list);
int				ft_check_pipe_syntax(t_tokens_list *list);
int				syntax_error(char token);
int				ft_check_append_syntax(t_tokens_list *list);
int				ft_check_herdoc_syntax(t_tokens_list *list);
int				ft_check_word_syntax(t_tokens_list *token);
int				ft_check_syntax(t_tokens_list *list);
void			ft_skip_tokens_spaces(t_tokens_list **tokens);
// expanding functions
char			*ft_expand(char *original, t_env_list *env);
char			*ft_extract_key(char *str);
char			**ft_split_keys(char *value);
int				ft_join_key(char *buffer, char *value, int index);
char			*ft_get_value(char *key, t_env_list *env);
void			ft_handle_expand_1(char *buffer, int *i, int *j, int *index);
void			ft_count_1(int *len, int *index);
void			ft_count_2(char *value, t_env_list *env, int *len);
void			ft_init_value(int *i, int *j, int *index);
void			ft_increment(int *i, int *j);
// here doc functions
t_heredoc		*ft_add_heredoc(t_heredoc **heredoc_list,
					t_tokens_list *tokens);
t_heredoc		*ft_create_heredoc(t_tokens_list **tokens, int list_size);
int				ft_count_heredoc(t_heredoc **heredoc_list);
void			ft_heredoc_addback(t_heredoc **lst, t_heredoc *new);
void			ft_print_heredoc(t_heredoc *heredoc);
int				ft_open_heredoc(t_heredoc *heredoc_list, t_env_list *env_list);
int				ft_heredoc_done(t_heredoc *heredoc_list);
void			sig_handler(int sig);
void			ft_re_open(t_heredoc **tmp);
// utils functions	
int				ft_array_len(char **array);
char			*ft_remove_quotes(char *str);
char			**ft_get_expand_split(char *value, t_env_list *env_list);
// env functions
t_env_list		*get_env_list(char	**env);
void			add_back_for_env(t_env_list	**list, char *str);
void			print_env_list(t_env_list *list);
// files functions
t_command_files	*ft_add_files(t_command_files **files_list,
					t_tokens_list *tokens, t_env_list *env_list);
t_command_files	*ft_create_files(t_tokens_list **tokens, t_env_list *env_list);
void			ft_files_addback(t_command_files **files_list,
					t_command_files *new);
void			ft_handle_redirection(t_command_files *file,
					t_tokens_list **tokens, t_env_list *env_list);
char			*ft_get_files_type(t_token_type type);
void			ft_printf_files(t_command_files *files);
void			ft_open_files(t_command_files *files);
int				ft_is_valid_redirection(t_token_type type);
int				ft_check_ambig(t_command_files *files);
char			*get_is_true(bool is_true);
char			*ft_get_file_name(t_tokens_list **tokens, t_env_list *env_list);
// commands functions
t_command		*ft_create_command(t_tokens_list **tokens,
					t_env_list *env_list);
void			ft_command_addback(t_command **alst, t_command *new);
int				ft_check_word_valid(t_token_type type);
int				ft_check_redirection_valid(t_token_type type);
void			ft_print_commands(t_command *command_list);
void			ft_print_command_args(t_command *command);
t_command		*ft_add_command(t_command **command_list,
					t_tokens_list *tokens, t_env_list *env_list);
char			*ft_join_token_value(t_tokens_list **tokens,
					t_env_list *env_list);
void			ft_command_assign_fds(t_command *cmd,
					t_command_files *f_list, t_heredoc *h_list);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_free_command_value(char *value, char *expand, char *tmp);
char			*ft_get_command_tmp(t_tokens_list **tokens);
int				ft_get_command_value(char **value,
					char **expand, char **tmp, t_tokens_list **tokens);
char			**ft_expand_value(char *value);
// clean functions
void			ft_clean_tokens(t_tokens_list **tokens_list);
void			ft_clean(t_be_executed *to_execute, char **array, char *line);
void			ft_clean_array(char **array);
void			ft_clean_commands(t_command **command_list);
void			ft_clean_files(t_command_files **files);
void			ft_clean_heredoc(t_heredoc **heredoc);
void			ft_clean_pipes(t_pipe **list_pipes);
void			ft_clean_env(t_env_list *env_list);
// execution function
t_be_executed	*give_executed(void);
void			fill_command_paths(t_command *command_list, t_env_list *env);
void			assign_output(t_command	*command, t_be_executed	*to_execute);
void			assign_input(t_command	*command, t_be_executed	*to_execute);
int				get_pipe_fd(t_pipe *list_pipes, int index, char c);
int				get_file_fd(t_command	*command, char i_o);
int				count_list(t_command	*list);
void			execute_command(t_command *command,
					t_be_executed	*to_execute);
void			execute_things(t_be_executed	*to_execute);
int				ft_is_executed(t_command *command);
void			ft_check_path_correct(char *cmd);
int				ft_is_path(char *cmd);
int				is_built_in(char	*command);
void			close_pipes(t_pipe *list_pipes);
char			**append_to_array(char **array, char *str);
void			increament_elems(t_pipe	**list_pipes, int *i,
					t_pipe **previous);
void			assign_fd_heredc(int *fd, t_command *command);
void			assign_fd_append(int *fd, t_command *command);
void			prror_exit(char *str, char *file);
// builtins functions
void			our_pwd(t_command *command,
					t_be_executed	*to_execute, int procss);
void			our_env(t_command *command,
					t_be_executed	*to_execute, int procss);
void			our_echo(t_command *command, int procss);
int				ft_strlen(char *s);
void			add_back_for_env(t_env_list **list, char *str);
t_env_list		*get_env_list(char **env);
void			print_env_list(t_env_list *list);
void			ft_export_env(t_env_list *env_list, int procss);
void			ft_export(t_command *command,
					t_be_executed	*to_execute, int procss);
void			ft_unset(t_command *command,
					t_be_executed	*to_execute, int procss);
void			our_cd(t_command *command,
					t_be_executed	*to_execute, int procss);
void			our_exit(t_command *command,
					t_be_executed	*to_execute, int procss);
char			**give_array_str(t_env_list *env_list);
void			close_other_pipes(t_command	*command, t_pipe *list_pipes);
void			add_to_env(char	*key, char	*value, t_env_list	**env_list);
int				check_every_arg(char *arg);
int				count_array_str(char **array);
void			error_handler(int *exit_stt,
					char *key, char *value, int procss);
int				is_in_list(char *key, t_env_list *env_list);
int				count_array_str(char **array);
// setup
int				ft_setup(t_be_executed **exec, char **tokens);

#endif