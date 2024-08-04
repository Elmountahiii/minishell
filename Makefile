NAME = minishell
minibuiltins = miniBuiltIns
CC = cc -g -fsanitize=address
# -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror  
#  -g -fsanitize=address
READLINE = -lreadline -lncurses
bSRC = builtins/env.c builtins/pwd.c builtins/cd.c builtins/echo.c builtins/print_env_list.c builtins/add_back_for_env.c builtins/get_env_list.c builtins/export.c builtins/unset.c builtins/ft_export_env.c builtins/exit.c
SRC = main.c lexer/ft_special_char.c lexer/ft_count_lexer_tokens.c lexer/ft_extract.c lexer/ft_init_token_list.c \
		lexer/ft_print_tokens_info.c lexer/ft_split_to_command.c lexer/ft_print_command_info.c lexer/ft_lstadd_back.c lexer/ft_lstnew.c lexer/ft_split_to_command_2.c\
		lexer/print_list_files.c lexer/give_list_files.c lexer/ft_check_syntax.c lexer/ft_clean_string.c lexer/ft_join_until_space.c lexer/ft_check_syntax_2.c \
		lexer/give_list_pipes.c lexer/print_list_pipes.c lexer/count_list.c lexer/fill_command_paths.c lexer/split_to_command_utils.c lexer/ft_clean_string_2.c \
		lexer/init_execute.c $(bSRC) execution/execute_things.c execution/is_built_in.c execution/execute_commmand.c execution/assign_in_out.c lexer/ft_expend.c lexer/ft_expand_utils.c lexer/ft_expand_2.c
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
	@$(CC) $(CFLAGS) lib/lib.a $(READLINE) -o $(NAME) $(OBJ)

clean:
	@cd lib && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd lib && make fclean
	@rm -f $(NAME)
	@rm -f $(miniBuiltIns)

re: fclean all 

.PHONY: all clean fclean re