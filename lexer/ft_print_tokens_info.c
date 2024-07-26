/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:56:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/26 18:48:21 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_table_header() {
    printf("|----------------------|----------------------|----------------------|\n");
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
	if (token_type == SINGLE_QUOTE_WORD)
		return ("SINGLE_QUOTE_WORD");
	if (token_type == DOUBLE_QUOTE_WORD)
		return ("DOUBLE_QUOTE_WORD");
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

void print_table_row(t_tokens_list *token) {
	printf("|   '%s'    ->    %s   |\n", token->value, ft_print_token_type(token->type));
}
void	ft_print_tokens_info(t_tokens_list *head)
{

	printf("|--------------------------|\n");
	printf("|** value  -> token_type **|\n");
	printf("|--------------------------|\n");
	
	while (head)
	{
		print_table_row(head);
		printf("|--------------------------|\n");
		head = head->next;
	}
}
