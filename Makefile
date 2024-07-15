NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror 
READLINE = -lreadline -lncurses
SRC = *.c lexer/ft_lexical_spliter.c lexer/ft_special_char.c lexer/ft_count_lexer_tokens.c lexer/ft_extract.c
OBJ = $(SRC:.c=.o)
HEADR = minishell.h

all: $(NAME)

%.o: %.c $(HEADR)
	$(CC) $(CFLAGS) -c $< -o $@

mc : all clean
	./minishell

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