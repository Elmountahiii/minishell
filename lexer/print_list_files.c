/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:16:34 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/26 18:18:42 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    print_list_files(t_list_files  *list_files)
{
    while (list_files)
    {
        printf("fd : %i ",list_files->fd);
        printf("name :%s\n",list_files->name);
        list_files = list_files->next;
    }
}
