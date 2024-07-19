NAME = minishell
minibuiltins = miniBuiltIns
CC = cc
CFLAGS = -Wall -Wextra -Werror   -g -fsanitize=address
READLINE = -lreadline -lncurses
SRC = *.c lexer/ft_lexical_spliter.c lexer/ft_special_char.c lexer/ft_count_lexer_tokens.c lexer/ft_extract.c lexer/ft_init_token_list.c lexer/ft_print_tokens_info.c lexer/ft_split_to_command.c lexer/ft_print_command_info.c
bSRC = builtins/main.c
OBJ = $(SRC:.c=.o)
HEADR = minishell.h

all: $(NAME)

%.o: %.c $(HEADR)
	@$(CC) $(CFLAGS) -c $< -o $@

mc : all clean
	./minishell

$(minibuiltins): $(bSRC)
	@$(CC) $(CFLAGS) $(bSRC) -o $(minibuiltins)

$(NAME): $(OBJ)
	@cd lib && make
	@$(CC) $(CFLAGS) lib/lib.a $(READLINE) -o $(NAME) $(OBJ)

clean:
	@cd lib && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd lib && make fclean
	@rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re