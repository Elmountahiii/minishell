/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:56:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/15 16:49:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_table_header() {
    printf("|----------------------|----------------------|----------------------|\n");
    printf("|       value          |        word_type     |        token_type    |\n");
    printf("|----------------------|----------------------|----------------------|\n");
}


void print_table_footer() {
	printf("|----------------------|----------------------|----------------------|\n");
}

char* ft_print_token_type(t_token_type token_type)
{
	if (token_type == WORD)
		return ("WORD");
	if (token_type == SPACE)
		return ("SPACE");
	if (token_type == PIPE)
		return ("PIPE");
	if (token_type == SINGLE_QUOTE)
		return ("SINGLE_QUOTE");
	if (token_type == DOUBLE_QUOTE)
		return ("DOUBLE_QUOTE");
	if (token_type == REDIRECTION_IN)
		return ("REDIRECTION_IN");
	if (token_type == REDIRECTION_OUT)
		return ("REDIRECTION_OUT");
	if (token_type == APPEND)
		return ("APPEND");
	if (token_type == HEREDOC)
		return ("HEREDOC");
	if (token_type == ENV)
		return ("ENV");
	return ("UNKNOWN");
}

char* get_word_type(t_word_type word_type)
{
	if (word_type == NORMAL)
		return "NORMAL";
	if (word_type == IN_SINGLE_QUOTE)
		return "IN_SINGLE_QUOTE";
	if (word_type == IN_DOUBLE_QUOTE)
		return "IN_DOUBLE_QUOTE";
	return "UNKNOWN";
}
void print_table_row(t_tokens_list *head) {
	if (head == NULL || head->token == NULL)
		return;
	printf("|   '%s'    |    %s   |   %s    |\n",head->token->value,get_word_type(head->token->word_type),ft_print_token_type(head->token->token_type));
}
void	ft_print_tokens_info(t_tokens_list *head)
{
	print_table_header();
	while (head)
	{
		print_table_row(head);
		head = head->next;
	}
	print_table_footer();
}
