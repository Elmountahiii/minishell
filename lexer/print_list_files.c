/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:16:34 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/08 12:41:10 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    print_list_files(t_list_files  *list_files)
{
    while (list_files)
    {
        printf("id : %i ",list_files->id);
        printf("fd : %i ",list_files->fd);
        printf("name :%s\n",list_files->name);
        list_files = list_files->next;
    }
}
