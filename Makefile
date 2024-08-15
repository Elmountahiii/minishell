NAME = minishell
minibuiltins = miniBuiltIns
CC = cc 
# -g -fsanitize=address
# -g -fsanitize=address
READ_LIB= -L/goinfre/$(USER)/homebrew/opt/readline/lib
READ_INCL= -I/goinfre/$(USER)/homebrew/opt/readline/include

CFLAGS = -Wall -Wextra -Werror 
#-g -fsanitize=address
READLINE = -lreadline -lncurses

builtins_files = add_back_for_env.c cd.c echo.c env.c exit.c export.c ft_export_env.c get_env_list.c print_env_list.c \
pwd.c unset.c 
files_files = ft_create_file_node.c ft_files_addback.c ft_files_last.c ft_hanlde_file_name.c ft_heredoc_last.c ft_select_files.c ft_open_files.c
clean_files = ft_clean.c ft_clean_commands.c ft_clean_files.c ft_clean_heredoc.c ft_clean_pipes.c ft_clean_tokens.c ft_free_array.c
execution_files = init_execute.c
expand_files = ft_tokens_expand.c ft_extract_key.c ft_link_key_value.c ft_expand_utils2.c
heredoc_files = ft_fill_heredoc.c ft_open_heredoc.c ft_init_heredoc.c
pipes_files = give_list_pipes.c

# new
spiting_files = ft_count_line_tokens.c ft_is_token.c ft_line_split.c ft_split_quotes_utils.c ft_split_space_utils.c ft_split_word_utils.c ft_split_redirection_utils.c \
ft_print_array.c ft_split_env_utils.c 
tokens_files = ft_create_token.c ft_tokens_addback.c  ft_add_tokens.c ft_print_tokens.c ft_token_skip.c
syntax_files = ft_check_syntax.c ft_check_syntax_2.c 
tokens_pre = $(addprefix tokens/, $(tokens_files))
spliting_pre = $(addprefix spliting/, $(spiting_files))
syntax_pre = $(addprefix syntax/, $(syntax_files))



builtins_prefix = $(addprefix builtins/, $(builtins_files))
clean_prefix = $(addprefix clean/, $(clean_files))
files_prefix = $(addprefix files/, $(files_files))
expand_prefix = $(addprefix expand/, $(expand_files))
execution_prefix = $(addprefix execution/, $(execution_files))
heredoc_prefix = $(addprefix heredoc/, $(heredoc_files))

SRC = main.c  $(execution_prefix) $(tokens_pre) $(spliting_pre) $(syntax_pre)
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