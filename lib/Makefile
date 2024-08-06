NAME = lib.a
HEADER = lib.h
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = ft_strchr.c ft_strlen.c ft_split_dil.c  ft_count_words_dil.c ft_split.c ft_count_words.c  ft_is_space.c ft_strnstr.c ft_print.c \
ft_free_split.c ft_substr_dil.c ft_substr.c  ft_split_count.c ft_strjoin.c ft_join_three.c ft_strdup.c ft_is_quote.c ft_substr_orig.c\
ft_count_allocation.c ft_skip_space.c ft_skip_quotes.c ft_count_quote_allocation.c ft_error_exit.c ft_command_not_found.c \
ft_strncmp.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_strcmp.c ft_is_metachar.c ft_is_append.c \
ft_is_heredoc.c ft_count_alloc.c ft_calloc.c ft_bzero.c ft_is_all_space.c ft_strcpy.c ft_atoi.c ft_itoa.c ft_isalnum.c
OBJ = $(SRC:.c=.o)
RM = rm -rf
AR = ar rcs

%.o : %.c HEADER
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR)  $(NAME) $(OBJ)

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re
