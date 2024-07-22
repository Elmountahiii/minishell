/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:24:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/21 20:01:58 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_pipe_syntax(t_tokens_list *list)
{
	if ( !list)
		return (1);
	if (list->type == PIPE)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == PIPE )
			{
				printf("syntax error near unexpected token `|'\n");
				return (1);
			}
			
		}else
		{
			// print this message to stderr
			printf("syntax error near unexpected token `|'\n");
			return (1);
		}
			
	}
	return (0);
}

int ft_check_redin_syntax(t_tokens_list *list)
{
	if ( !list  )
		return (1);
	if (list->type == REDIRECTION_IN)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == REDIRECTION_IN)
			{
				printf("syntax error near unexpected token `<'\n");
				return (1);
			}else if (list->type == PIPE)
			{
				printf("syntax error near unexpected token `|'\n");
				return (1);
			}else if (list->type == REDIRECTION_OUT)
			{
				printf("syntax error near unexpected token `>'\n");
				return (1);
			} else if (list->type == APPEND)
			{
				printf("syntax error near unexpected token `>>'\n");
				return (1);
			}
		}else
		{
			printf("syntax error near unexpected token `<'\n");
			return (1);
		}
	}
	return (0);
}

int ft_check_redout_syntax(t_tokens_list *list)
{
	if ( !list )
		return (1);
	if (list->type == REDIRECTION_OUT)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == REDIRECTION_OUT)
			{
				printf("syntax error near unexpected token `>'\n");
				return (1);
			}else if (list->type == REDIRECTION_IN)
			{
				printf("syntax error near unexpected token `<'\n");
				return (1);
			} else if (list->type == APPEND)
			{
				printf("syntax error near unexpected token `>>'\n");
				return (1);
			}else
			{
				printf("syntax error near unexpected token `|'\n");
				return (1);
			}
		}
		else
		{
			printf("syntax error near unexpected token `>'\n");
			return (1);
		}	
	}
	return (0);
}

int	ft_check_append_syntax(t_tokens_list *list)
{
	if ( !list )
		return (1);
	if (list->type == APPEND)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == APPEND)
			{
				printf("syntax error near unexpected token `>>'\n");
				return (1);
			}else if (list->type == REDIRECTION_IN)
			{
				printf("syntax error near unexpected token `<'\n");
				return (1);
			}else if (list->type == REDIRECTION_OUT)
			{
				printf("syntax error near unexpected token `>'\n");
				return (1);
			}else
			{
				printf("syntax error near unexpected token `|'\n");
				return (1);
			}
		}else
		{
			printf("syntax error near unexpected token `newline'\n");
			return (1);
		}
	}
	return (0);
}

int ft_check_herdoc_syntax(t_tokens_list *list)
{
	if ( !list )
		return (1);
	if (list->type == HEREDOC)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == HEREDOC)
			{
				printf("syntax error near unexpected token `<<'\n");
				return (1);
			}else if (list->type == REDIRECTION_IN)
			{
				printf("syntax error near unexpected token `<'\n");
				return (1);
			}else if (list->type == REDIRECTION_OUT)
			{
				printf("syntax error near unexpected token `>'\n");
				return (1);
			}else if (list->type == APPEND)
			{
				printf("syntax error near unexpected token `>>'\n");
				return (1);
			}else
			{
				printf("syntax error near unexpected token `|'\n");
				return (1);
			}
		}else
		{
			printf("syntax error near unexpected token `newline'\n");
			return (1);
		}
	}
	return (0);

}

int ft_check_syntax(t_tokens_list *list)
{
	t_tokens_list *tmp;

	tmp = list;
	if (list->type == PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		return (1);
	}
	while (tmp)
	{
		if (ft_check_pipe_syntax(tmp))
				return (1);
		if (ft_check_redin_syntax(tmp))
				return (1);
		if (ft_check_redout_syntax(tmp))
				return (1);
		if (ft_check_append_syntax(tmp))
		 	return (1);
		if (ft_check_herdoc_syntax(tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
