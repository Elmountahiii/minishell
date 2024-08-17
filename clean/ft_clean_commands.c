/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:46:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 14:52:14 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_commands(t_command **command_list)
{
    t_command *tmp;
   
    while (command_list && (*command_list))
    {
        free((*command_list)->path);
        (*command_list)->path = NULL;

        ft_clean_array((*command_list)->command_args);
        (*command_list)->command_args = NULL;

        free((*command_list)->in_file);
        (*command_list)->in_file = NULL;

        free((*command_list)->out_file);
        (*command_list)->out_file = NULL;

        free((*command_list)->dil);
        (*command_list)->dil = NULL;

        free((*command_list)->ambiguous_name);
        (*command_list)->ambiguous_name = NULL;
        tmp = (*command_list)->next;
        free((*command_list));
        (*command_list) = tmp;
    }

}