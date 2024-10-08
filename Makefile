NAME = minishell
CC = cc 
READ_LIB= -L/goinfre/$(USER)/homebrew/opt/readline/lib
READ_INCL= -I/goinfre/$(USER)/homebrew/opt/readline/include

CFLAGS = -Wall -Wextra -Werror
READLINE = -lreadline -lncurses

wildcard_files = wild.c wild_utils.c
spiting_files = ft_count_line_tokens.c ft_is_token.c ft_line_split.c ft_split_quotes_utils.c ft_split_space_utils.c ft_split_word_utils.c ft_split_redirection_utils.c \
ft_print_array.c ft_split_env_utils.c 
tokens_files = ft_create_token.c ft_tokens_addback.c  ft_add_tokens.c ft_print_tokens.c ft_token_skip.c
syntax_files = ft_check_syntax.c ft_check_syntax_2.c 
heredoc_files = ft_add_heredoc.c ft_create_heredoc.c ft_heredoc_len.c ft_heredoc_addback.c ft_printf_heredoc.c ft_open_heredoc.c ft_heredoc_done.c ft_heredoc_utils.c
expand_files = ft_expand.c ft_extract_key.c ft_get_expand_keys.c ft_expand_utils.c 
utils_files = ft_array_len.c ft_remove_quotes.c ft_get_expand_split.c ft_has_quotes.c
env_files = get_env_list.c add_back_for_env.c ft_print_env_list.c
files_files = ft_add_files.c ft_create_file.c ft_files_addback.c ft_print_files.c ft_open_files.c ft_check_ambig.c ft_files_uils.c
commands_files = ft_command_addback.c ft_create_command.c ft_print_command_args.c ft_add_commands.c ft_print_commands.c ft_commands_utils.c ft_command_assign_fds.c ft_commands_utils2.c ft_command_utils3.c
clean_files = ft_clean_tokens.c ft_clean_array.c ft_clean.c ft_clean_commands.c ft_clean_files.c  ft_clean_heredoc.c ft_clean_pipes.c ft_clean_env.c
setup_files = ft_setup.c
builtins_files = cd.c echo.c env.c exit.c export.c ft_export_env.c pwd.c unset.c count_array.c close_other_pipes.c
pipes_files = give_list_pipes.c
execution_files = assign_in_out.c count_list.c execute_commmand.c execute_things.c fill_command_paths.c ft_is_executed.c \
ft_is_path.c init_execute.c is_built_in.c give_array_fromenv.c close_pipes.c append_or_herdoc.c increament_elems.c ft_exec_utils.c
utils_pre = $(addprefix utils/, $(utils_files))
tokens_pre = $(addprefix tokens/, $(tokens_files))
spliting_pre = $(addprefix spliting/, $(spiting_files))
syntax_pre = $(addprefix syntax/, $(syntax_files))
heredoc_pre = $(addprefix heredoc/, $(heredoc_files))
expand_pre = $(addprefix expand/, $(expand_files))
env_pre = $(addprefix env/, $(env_files))
files_pre = $(addprefix files/, $(files_files))
commands_pre = $(addprefix commands/, $(commands_files))
clean_pre = $(addprefix clean/, $(clean_files))
pipes_pre = $(addprefix pipes/, $(pipes_files))
execution_pre = $(addprefix execution/, $(execution_files))
builtins_pre = $(addprefix builtins/, $(builtins_files))
setup_pre = $(addprefix setup/, $(setup_files))
wildcard_pre = $(addprefix wildcards/, $(wildcard_files))
AR = ./lib/lib.a

SRC = main.c  $(execution_pre) $(tokens_pre) $(spliting_pre) $(syntax_pre)  $(heredoc_pre) $(utils_pre)  $(expand_pre) $(env_pre) $(files_pre) $(commands_pre) $(clean_pre) \
$(pipes_pre) $(builtins_pre)  $(setup_pre) $(wildcard_pre)
OBJ = $(SRC:.c=.o)
HEADR = minishell.h

all: $(NAME)

%.o: %.c $(HEADR)
	$(CC) $(CFLAGS) $(READ_INCL) -c $< -o $@

$(AR):
	make -C lib

$(NAME): $(AR) $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) $(READ_LIB) lib/lib.a $(READLINE) -o $(NAME)

clean:
	@cd lib && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd lib && make fclean
	@rm -f $(NAME)
	@rm -f $(miniBuiltIns)

re: fclean all 

.PHONY: all clean fclean re