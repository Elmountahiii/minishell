NAME = minishell
minibuiltins = miniBuiltIns
CC = cc 
# -g -fsanitize=address
# -g -fsanitize=address
READ_LIB= -L/goinfre/$(USER)/homebrew/opt/readline/lib
READ_INCL= -I/goinfre/$(USER)/homebrew/opt/readline/include

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
READLINE = -lreadline -lncurses
files_files = ft_create_file_node.c ft_files_addback.c ft_files_last.c ft_hanlde_file_name.c ft_heredoc_last.c ft_select_files.c ft_open_files.c
clean_files = ft_clean.c ft_clean_commands.c ft_clean_files.c ft_clean_heredoc.c ft_clean_pipes.c ft_clean_tokens.c ft_free_array.c
expand_files = ft_tokens_expand.c ft_extract_key.c ft_link_key_value.c ft_expand_utils2.c
clean_prefix = $(addprefix clean/, $(clean_files))
files_prefix = $(addprefix files/, $(files_files))
expand_prefix = $(addprefix expand/, $(expand_files))
bSRC = builtins/env.c builtins/pwd.c builtins/cd.c builtins/echo.c builtins/print_env_list.c builtins/add_back_for_env.c builtins/get_env_list.c builtins/export.c builtins/unset.c builtins/ft_export_env.c builtins/exit.c
SRC = main.c lexer/ft_special_char.c lexer/ft_count_lexer_tokens.c lexer/ft_extract.c lexer/ft_init_token_list.c \
		lexer/ft_print_tokens_info.c lexer/ft_split_to_command.c lexer/ft_print_command_info.c lexer/ft_lstadd_back.c lexer/ft_lstnew.c lexer/ft_split_to_command_2.c\
		lexer/print_list_files.c lexer/give_list_files.c lexer/ft_check_syntax.c lexer/ft_clean_string.c lexer/ft_join_until_space.c lexer/ft_check_syntax_2.c \
		lexer/give_list_pipes.c lexer/print_list_pipes.c lexer/count_list.c lexer/fill_command_paths.c lexer/split_to_command_utils.c lexer/ft_clean_string_2.c \
		lexer/init_execute.c $(bSRC) execution/execute_things.c execution/is_built_in.c execution/execute_commmand.c execution/assign_in_out.c lexer/ft_expend.c lexer/ft_expand_utils.c lexer/ft_expand_2.c   \
		 execution/ft_fill_heredoc.c execution/ft_open_heredoc.c execution/ft_init_heredoc.c  lexer/ft_remove_quotes.c lexer/ft_create_heredoc.c lexer/ft_heredoc_addback.c lexer/ft_heredoc_size.c execution/ft_is_executed.c \
		execution/ft_is_path.c $(files_prefix) $(clean_prefix) $(expand_prefix)
OBJ = $(SRC:.c=.o)
HEADR = minishell.h

all: $(NAME)

%.o: %.c $(HEADR)
	@$(CC) $(CFLAGS) -c $< -o $@

mc : all clean
	clear
	./minishell

$(minibuiltins): $(bSRC)
	$(CC) $(CFLAGS) lib/lib.a $(bSRC) -o $(minibuiltins)

$(NAME): $(OBJ)
	@cd lib && make
	@$(CC) $(CFLAGS)  $(OBJ) lib/lib.a $(READLINE) -o $(NAME)

clean:
	@cd lib && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd lib && make fclean
	@rm -f $(NAME)
	@rm -f $(miniBuiltIns)

re: fclean all 

.PHONY: all clean fclean re