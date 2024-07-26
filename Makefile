NAME = minishell
minibuiltins = miniBuiltIns
CC = cc
CFLAGS = -Wall -Wextra -Werror  
#  -g -fsanitize=address
READLINE = -lreadline -lncurses
bSRC = builtins/main.c builtins/env.c builtins/pwd.c builtins/cd.c builtins/echo.c builtins/print_env_list.c builtins/add_back_for_env.c builtins/get_env_list.c builtins/export.c builtins/unset.c
SRC = main.c lexer/ft_lexical_spliter.c lexer/ft_special_char.c lexer/ft_count_lexer_tokens.c lexer/ft_extract.c lexer/ft_init_token_list.c lexer/ft_print_tokens_info.c lexer/ft_split_to_command.c lexer/ft_print_command_info.c lexer/ft_lstadd_back.c lexer/ft_lstnew.c \
		lexer/print_list_files.c lexer/give_list_files.c lexer/ft_check_syntax.c lexer/ft_clean_string.c lexer/ft_join_until_space.c lexer/give_list_pipes.c lexer/print_list_pipes.c
OBJ = $(SRC:.c=.o)
HEADR = minishell.h

all: $(NAME)

%.o: %.c $(HEADR)
	@$(CC) $(CFLAGS) -c $< -o $@

mc : all clean
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